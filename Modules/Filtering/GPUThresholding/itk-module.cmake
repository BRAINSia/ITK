set(DOCUMENTATION "This module contains the GPU implementation for image
thresholding filters such as the classical binary thresholding.")

itk_module(ITKGPUThresholding
  DEPENDS
    ITKCommon
    ITKGPUCommon
  USE_DEPENDS
    ITKThresholding
  LINK_DEPENDS
    ${OPENCL_LIBRARIES}
  TEST_DEPENDS
    ITKTestKernel
    ITKGPUSmoothing
  DESCRIPTION
    "${DOCUMENTATION}"
)
