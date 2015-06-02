set(DOCUMENTATION "This module contains classes that provide an
interface between ITK and VTK.")

itk_module(ITKVtkGlue
  DEPENDS
    ITKCommon
    ITKVTK
  USE_DEPENDS
    ITKImageIntensity
    ITKImageAdaptors
    ITKImageGrid
  LINK_DEPENDS
    ${ITKVtkGlue_VTK_LIBRARIES}
    ${ITKVtkGlue_VTK_LIBRARIES_EXPLICIT}
  TEST_DEPENDS
    ITKTestKernel
    ITKSmoothing
    ITKImageCompose
  EXCLUDE_FROM_DEFAULT
  DESCRIPTION
    "${DOCUMENTATION}")

# extra test dependency on Smoothing is introduced by itkVtkMedianImagefilterTest.
# extra test dependency on ImageCompose is introduced by QuickViewTest.
