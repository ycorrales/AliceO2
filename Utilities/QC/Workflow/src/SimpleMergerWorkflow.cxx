// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// @file   SimpleMergerWorkflow
/// @author Matthias Richter
/// @since  2017-11-10
/// @brief  A workflow definition for a simple ROOT object merger example

#include "Framework/WorkflowSpec.h"
#include "Framework/runDataProcessing.h"
#include "RootObjectProducerSpec.h"
#include "RootObjectMergerSpec.h"

using namespace o2::framework;

/// This function is required to be implemented to define the workflow
/// specifications
///
/// The example connects a producer for ROOT objects with a merger process
WorkflowSpec defineDataProcessing(ConfigContext const &) {
  return WorkflowSpec{
    o2::qc::getRootObjectProducerSpec(),
    o2::qc::getRootObjectMergerSpec()
  };
}
