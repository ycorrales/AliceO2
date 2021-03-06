# Copyright CERN and copyright holders of ALICE O2. This software is
# distributed under the terms of the GNU General Public License v3 (GPL
# Version 3), copied verbatim in the file "COPYING".
#
# See http://alice-o2.web.cern.ch/ for full licensing information.
#
# In applying this license CERN does not waive the privileges and immunities
# granted to it by virtue of its status as an Intergovernmental Organization
# or submit itself to any jurisdiction.

set(MODULE_NAME "Framework")

set(MODULE_BUCKET_NAME O2FrameworkCore_bucket)

O2_SETUP(NAME ${MODULE_NAME})
if (GLFW_FOUND)
  set(GUI_SOURCES src/FrameworkGUIDebugger.cxx)
else()
  set(GUI_SOURCES src/FrameworkDummyDebugger.cxx)
endif()

set(SRCS
    src/BoostOptionsRetriever.cxx
    src/ConfigParamsHelper.cxx
    src/CompletionPolicy.cxx
    src/ChannelSpecHelpers.cxx
    src/CompletionPolicyHelpers.cxx
    src/ChannelConfigurationPolicy.cxx
    src/ChannelConfigurationPolicyHelpers.cxx
    src/DataAllocator.cxx
    src/DataProcessingDevice.cxx
    src/DataProcessingHeader.cxx
    src/DataProcessor.cxx
    src/DataRelayer.cxx
    src/DataSampling.cxx
    src/DataSamplingConditionRandom.cxx
    src/DataSamplingConditionPayloadSize.cxx
    src/DataSamplingConditionNConsecutive.cxx
    src/DataSamplingConditionFactory.cxx
    src/DataSamplingReadoutAdapter.cxx
    src/DataSourceDevice.cxx
    src/DeviceMetricsInfo.cxx
    src/DeviceSpec.cxx
    src/DeviceSpecHelpers.cxx
    src/DDSConfigHelpers.cxx
    src/DispatcherDPL.cxx
    src/DispatcherFairMQ.cxx
    src/DispatcherFlpProto.cxx
    src/DriverControl.cxx
    src/DriverInfo.cxx
    src/FairOptionsRetriever.cxx
    src/FairMQDeviceProxy.cxx
    src/FairMQResizableBuffer.cxx
    src/GraphvizHelpers.cxx
    src/InputRecord.cxx
    src/LocalRootFileService.cxx
    src/LogParsingHelpers.cxx
    src/ExternalFairMQDeviceProxy.cxx
    src/SimpleResourceManager.cxx
    src/TextControlService.cxx
    src/TableBuilder.cxx
    src/TableConsumer.cxx
    src/WorkflowHelpers.cxx
    src/WorkflowSpec.cxx
    src/runDataProcessing.cxx
    src/Task.cxx
    src/TMessageSerializer.cxx
    src/StreamOperators.cxx
    src/FrameworkGUIDevicesGraph.cxx
    src/FrameworkGUIDeviceInspector.cxx
    src/FrameworkGUIDataRelayerUsage.cxx
    src/PaletteHelpers.cxx
    ${GUI_SOURCES}
    test/TestClasses.cxx
    src/Variant.cxx
   )

set(HEADERS
      include/Framework
      include/Framework/DataProcessor.h
      include/Framework/DataSpecUtils.h
      include/Framework/FrameworkGUIDevicesGraph.h
      include/Framework/FrameworkGUIDataRelayerUsage.h
      include/Framework/DeviceMetricsInfo.h
      include/Framework/DeviceSpec.h
      include/Framework/DeviceControl.h
      include/Framework/InitContext.h
      include/Framework/ServiceRegistry.h
      include/Framework/DeviceExecution.h
      include/Framework/DebugGUI.h
      include/Framework/TypeTraits.h
      include/Framework/PaletteHelpers.h
      include/Framework/ConfigParamSpec.h
      include/Framework/TMessageSerializer.h
      include/Framework/DataProcessorLabel.h
      include/Framework/LogParsingHelpers.h
      include/Framework/InputSpec.h
      include/Framework/DeviceInfo.h
      include/Framework/BoostOptionsRetriever.h
      include/Framework/DataChunk.h
      include/Framework/FrameworkGUIDebugger.h
      include/Framework/runDataProcessing.h
      include/Framework/AlgorithmSpec.h
      include/Framework/ParamRetriever.h
      include/Framework/ErrorContext.h
      include/Framework/InputRecord.h
      include/Framework/DataProcessorSpec.h
      include/Framework/ConfigParamsHelper.h
      include/Framework/InputRoute.h
      include/Framework/ChannelConfigurationPolicyHelpers.h
      include/Framework/ForwardRoute.h
      include/Framework/MessageContext.h
      include/Framework/ChannelMatching.h
      include/Framework/RawDeviceService.h
      include/Framework/TextControlService.h
      include/Framework/DataAllocator.h
      include/Framework/ConfigParamRegistry.h
      include/Framework/DataRef.h
      include/Framework/WorkflowSpec.h
      include/Framework/LocalRootFileService.h
      include/Framework/OutputSpec.h
      include/Framework/ChannelSpec.h
      include/Framework/ChannelConfigurationPolicy.h
      include/Framework/DataSourceDevice.h
      include/Framework/SimpleRawDeviceService.h
      include/Framework/ExternalFairMQDeviceProxy.h
      include/Framework/ControlService.h
      include/Framework/DataRelayer.h
      include/Framework/DataRefUtils.h
      include/Framework/RootFileService.h
      include/Framework/OutputRoute.h
      include/Framework/DataProcessingHeader.h
      include/Framework/ProcessingContext.h
      include/Framework/FairOptionsRetriever.h
      include/Framework/ParallelContext.h
      include/Framework/RootObjectContext.h
      include/Framework/DataProcessingDevice.h
      include/Framework/Variant.h
      include/Framework/CallbackRegistry.h
      include/Framework/CallbackService.h
      include/Framework/DataSampling.h
      include/Framework/DataSamplingCondition.h
      include/Framework/DataSamplingConditionFactory.h
      include/Framework/DataSamplingReadoutAdapter.h
      include/Framework/DPLBoostSerializer.h
      include/Framework/TableBuilder.h
      include/Framework/FairMQResizableBuffer.h
      src/ComputingResource.h
      src/DDSConfigHelpers.h
      src/DeviceSpecHelpers.h
      src/DriverControl.h
      src/DriverInfo.h
      src/GraphvizHelpers.h
      src/ResourceManager.h
      src/SimpleResourceManager.h
      src/WorkflowHelpers.h
  )

set(LIBRARY_NAME ${MODULE_NAME})
set(BUCKET_NAME ${MODULE_BUCKET_NAME})

# create dictionary for a test class to be serialized in unit test
set(LINKDEF test/FrameworkCoreTestLinkDef.h)
set(HEADERS
     test/TestClasses.h
   )

O2_GENERATE_LIBRARY()

# TODO: feature of macro, it deletes the variables we pass to it, set them again
# this has to be fixed in the macro implementation
set(LIBRARY_NAME ${MODULE_NAME})
set(BUCKET_NAME ${MODULE_BUCKET_NAME})

O2_GENERATE_EXECUTABLE(
  EXE_NAME "test_SimpleDataProcessingDevice01"
  SOURCES "test/test_SimpleDataProcessingDevice01.cxx"
  MODULE_LIBRARY_NAME ${LIBRARY_NAME}
  BUCKET_NAME ${MODULE_BUCKET_NAME}
)

O2_GENERATE_EXECUTABLE(
  EXE_NAME "test_Parallel"
  SOURCES "test/test_Parallel.cxx"
  MODULE_LIBRARY_NAME ${LIBRARY_NAME}
  BUCKET_NAME ${MODULE_BUCKET_NAME}
)

O2_GENERATE_EXECUTABLE(
  EXE_NAME "test_TimePipeline"
  SOURCES "test/test_TimePipeline.cxx"
  MODULE_LIBRARY_NAME ${LIBRARY_NAME}
  BUCKET_NAME ${MODULE_BUCKET_NAME}
)

target_compile_options(Framework PUBLIC -O0 -g -fno-omit-frame-pointer)
target_compile_options(test_SimpleDataProcessingDevice01 PUBLIC -O0 -g -fno-omit-frame-pointer)

Install(FILES test/test_DataSamplingDPL.json test/test_DataSamplingFairMQ.json DESTINATION share/tests/)

set(TEST_SRCS
      test/test_SimpleStatefulProcessing01.cxx
      test/test_SimpleStringProcessing.cxx
      test/test_AlgorithmSpec.cxx
      test/test_BoostOptionsRetriever.cxx
      test/test_CompletionPolicy.cxx
      test/test_ChannelSpecHelpers.cxx
      test/test_DataRelayer.cxx
      test/test_DataSampling.cxx
      test/test_DataSamplingCondition.cxx
      test/test_DataRefUtils.cxx
      test/test_DataProcessorSpec.cxx
      test/test_DeviceMetricsInfo.cxx
      test/test_DeviceSpec.cxx
      test/test_FairMQResizableBuffer.cxx
      test/test_Forwarding.cxx
      test/test_FrameworkDataFlowToDDS.cxx
      test/test_Graphviz.cxx
      test/test_GUITests.cxx
      test/test_InputRecord.cxx
      test/test_ParallelProducer.cxx
      test/test_PtrHelpers.cxx
      test/test_LogParsingHelpers.cxx
      test/test_ExternalFairMQDeviceProxy.cxx
      test/test_Services.cxx
      test/test_SimpleRDataFrameProcessing.cxx
      test/test_SingleDataSource.cxx
      test/test_SuppressionGenerator.cxx
      test/test_TimeParallelPipelining.cxx
      test/test_TypeTraits.cxx
      test/test_Variants.cxx
      test/test_WorkflowHelpers.cxx
      test/test_TMessageSerializer.cxx
      test/test_DataAllocator.cxx
      test/test_CallbackRegistry.cxx
      test/test_Task.cxx
      test/test_TableBuilder.cxx
      test/test_InfoLogger.cxx
   )

O2_GENERATE_TESTS(
  MODULE_LIBRARY_NAME ${LIBRARY_NAME}
  BUCKET_NAME ${BUCKET_NAME}
  TEST_SRCS ${TEST_SRCS}
  TIMEOUT 30
)

# specific tests which needs command line options
O2_GENERATE_TESTS(
  MODULE_LIBRARY_NAME ${LIBRARY_NAME}
  BUCKET_NAME ${BUCKET_NAME}
  TIMEOUT 60

  TEST_SRCS
  test/test_ProcessorOptions.cxx

  COMMAND_LINE_ARGS
  --global-config require-me
  # Note: the group switch makes process consumer parse only the group arguments
  --consumer "--global-config consumer-config --local-option hello-aliceo2"
)
