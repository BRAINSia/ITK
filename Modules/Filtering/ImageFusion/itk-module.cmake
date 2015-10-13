set(DOCUMENTATION "This module contains classes made to visually
enhance the images, mostly by adding them artificial colors")

itk_module(ITKImageFusion
  ENABLE_SHARED_IF_EXPLICIT_INSTANTIATION
  COMPILE_DEPENDS
  DEPENDS_IF_EXPLICIT_INSTANTIATION
    ITKBinaryMathematicalMorphology
    ITKImageLabel
  TEST_DEPENDS
    ITKTestKernel
  DESCRIPTION
    "${DOCUMENTATION}"
)
