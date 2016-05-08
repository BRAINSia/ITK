set(DOCUMENTATION "This module contains multiple variations of image
thresholding filters. In addition to the classical binary thresholding, you
will find here the thresholding filters based on the Otsu criterion, both for
single and multiple thresholds.")

itk_module(ITKThresholding
  ENABLE_SHARED_IF_EXPLICIT_INSTANTIATION
  COMPILE_DEPENDS
  DEPENDS_IF_EXPLICIT_INSTANTIATION
    ITKImageIntensity
    ITKImageStatistics
  TEST_DEPENDS
    ITKTestKernel
    ITKSignedDistanceFunction
  DESCRIPTION
    "${DOCUMENTATION}"
)

# Extra test dependency on ITKSignedDistanceFunction  is introduced by itkBinaryThresholdSpatialFunctionTest.
# Extra test dependency on ITKSmoothing is introduced by itkBinaryThresholdProjectionImageFilterTest.
