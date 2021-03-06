// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#include "Framework/WorkflowSpec.h"
#include "Framework/DataProcessorSpec.h"
#include "Framework/runDataProcessing.h"
#include "Framework/DataAllocator.h"
#include "Framework/InputRecord.h"
#include "Framework/InputSpec.h"
#include "Framework/OutputSpec.h"
#include "Framework/ControlService.h"
#include "Utils/RootTreeReader.h"
#include "Headers/DataHeader.h"
#include "../../Core/test/TestClasses.h"
#include "FairMQLogger.h"
#include <TSystem.h>
#include <TTree.h>
#include <TFile.h>
#include <vector>

using namespace o2::framework;

#define ASSERT_ERROR(condition)                                   \
  if ((condition) == false) {                                     \
    LOG(ERROR) << R"(Test condition ")" #condition R"(" failed)"; \
  }

constexpr int kTreeSize = 10; // elements in the test tree
DataProcessorSpec getSourceSpec()
{
  auto initFct = [](InitContext& ic) {
    // create a test tree in a temporary file
    std::string fileName = gSystem->TempDirectory();
    fileName += "/test_RootTreeReader.root";

    {
      std::unique_ptr<TFile> testFile(TFile::Open(fileName.c_str(), "RECREATE"));
      std::unique_ptr<TTree> testTree = std::make_unique<TTree>("testtree", "testtree");

      std::vector<o2::test::Polymorphic> valarray;
      auto* branch = testTree->Branch("dataarray", &valarray);

      for (int entry = 0; entry < kTreeSize; entry++) {
        valarray.clear();
        for (int idx = 0; idx < entry + 1; ++idx) {
          valarray.emplace_back((entry * 10) + idx);
        }
        testTree->Fill();
      }
      testTree->Write();
      testTree->SetDirectory(nullptr);
      testFile->Close();
    }

    constexpr auto persistency = Lifetime::Transient;
    auto reader = std::make_shared<RootTreeReader>("testtree",       // tree name
                                                   fileName.c_str(), // input file name
                                                   Output{ "TST", "ARRAYOFDATA", 0, persistency },
                                                   "dataarray" // name of cluster branch
                                                   );

    auto processingFct = [reader](ProcessingContext& pc) { (++(*reader))(pc); };

    return processingFct;
  };

  return DataProcessorSpec{ "source", // name of the processor
                            {},
                            { OutputSpec{ "TST", "ARRAYOFDATA" } },
                            AlgorithmSpec(initFct) };
}

DataProcessorSpec getSinkSpec()
{
  auto processingFct = [](ProcessingContext& pc) {
    static int counter = 0;
    using DataHeader = o2::header::DataHeader;
    for (auto& input : pc.inputs()) {
      auto dh = o2::header::get<const DataHeader*>(input.header);
      LOG(INFO) << dh->dataOrigin.str << " " << dh->dataDescription.str << " " << dh->payloadSize;
    }
    auto data = pc.inputs().get<std::vector<o2::test::Polymorphic>>("input");

    LOG(INFO) << "count: " << counter << "  data elements:" << data.size();
    ASSERT_ERROR(counter + 1 == data.size());
    for (int idx = 0; idx < data.size(); idx++) {
      LOG(INFO) << data[idx].get();
      ASSERT_ERROR(data[idx].get() == 10 * counter + idx);
    }
    if (++counter >= kTreeSize) {
      pc.services().get<ControlService>().readyToQuit(true);
    }
  };

  return DataProcessorSpec{ "sink", // name of the processor
                            { InputSpec{ "input", "TST", "ARRAYOFDATA" } },
                            Outputs{},
                            AlgorithmSpec(processingFct) };
}

WorkflowSpec defineDataProcessing(ConfigContext const&)
{
  return WorkflowSpec{
    getSourceSpec(),
    getSinkSpec()
  };
}
