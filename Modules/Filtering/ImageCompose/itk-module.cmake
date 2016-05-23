set(DOCUMENTATION "This module contains filters that combine several images
into a single output image. For example, take several input scalar images and
package them into an output image of multiple components.")

itk_module(ITKImageCompose
  ENABLE_SHARED_IF_EXPLICIT_INSTANTIATION
  COMPILE_DEPENDS
  DEPENDS_IF_EXPLICIT_INSTANTIATION
    ITKImageFilterBase
  TEST_DEPENDS
    ITKTestKernel
  DESCRIPTION
    "${DOCUMENTATION}"
)
