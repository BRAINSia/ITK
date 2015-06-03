set(DOCUMENTATION "This module contains both I/O and bridging methods needed
for interacting with and utilizing OpenCV within ITK. This includes symetric
bridges for both image data and video data.")

itk_module(ITKVideoBridgeOpenCV
  EXPLICIT_DEPENDS
    ITKVideoCore
    ITKVideoIO
  LINK_DEPENDS
    ${OpenCV_LIBS}
  TEST_DEPENDS
    ITKTestKernel
  EXCLUDE_FROM_DEFAULT
  DESCRIPTION
    "${DOCUMENTATION}"
)
