// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.
#ifndef FRAMEWORK_DATASOURCE_DEVICE_H
#define FRAMEWORK_DATASOURCE_DEVICE_H

#include <fairmq/FairMQDevice.h>

#include "Framework/AlgorithmSpec.h"
#include "Framework/ConfigParamRegistry.h"
#include "Framework/DataAllocator.h"
#include "Framework/DeviceSpec.h"
#include "Framework/ArrowContext.h"
#include "Framework/ServiceRegistry.h"

#include <memory>
#include <cstddef>

namespace o2
{
namespace framework
{
/// Implements the boilerplate for a generic
/// framework device which only produces data
class DataSourceDevice : public FairMQDevice {
public:
  DataSourceDevice(const DeviceSpec &spec, ServiceRegistry &registry);
  void Init() final;
  void PreRun() final;
  void PostRun() final;
  void Reset() final;

 protected:
  bool ConditionalRun() final;
private:
  AlgorithmSpec::InitCallback mInit;
  AlgorithmSpec::ProcessCallback mStatefulProcess;
  AlgorithmSpec::ProcessCallback mStatelessProcess;
  AlgorithmSpec::ErrorCallback mError;

  std::unique_ptr<ConfigParamRegistry> mConfigRegistry;
  ServiceRegistry& mServiceRegistry;
  TimingInfo mTimingInfo;
  MessageContext mFairMQContext;
  RootObjectContext mRootContext;
  StringContext mStringContext;
  ArrowContext mDataFrameContext;
  ContextRegistry mContextRegistry;
  DataAllocator mAllocator;
  size_t mCurrentTimeslice;
  float mRate;
  size_t mLastTime;
};

} // namespace framework
} // namespace o2
#endif
