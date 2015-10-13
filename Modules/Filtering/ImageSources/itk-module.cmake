set(DOCUMENTATION "This module groups image sources which generate an image")

itk_module(ITKImageSources
  ENABLE_SHARED_IF_EXPLICIT_INSTANTIATION
  COMPILE_DEPENDS
  DEPENDS_IF_EXPLICIT_INSTANTIATION
    ITKCommon
  TEST_DEPENDS
    ITKTestKernel
    ITKImageIntensity
  DESCRIPTION
    "${DOCUMENTATION}"
)

# the ITKIntensity is only needed for the
# VectorIndexSelectionCastImageFilter for the PhysicalPointImageSourceTest
