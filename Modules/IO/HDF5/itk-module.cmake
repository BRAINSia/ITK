set(DOCUMENTATION "This module contains an ImageIO class for reading and writing
ITK Images stored in the <a href=\"http://www.hdfgroup.org/HDF5/\">HDF5</a>
data model and file format.")

itk_module(ITKIOHDF5
  ENABLE_SHARED
  DEPENDS
    ITKIOImageBase
    ITKHDF5
  USE_DEPENDS
    ITKCommon
  LINK_DEPENDS
    ${TEST_DEPENDS_LIBRARIES}
    ${ITKTestKernel_LIBRARIES}
  TEST_DEPENDS
    ITKTestKernel
    ITKImageSources
  DESCRIPTION
    "${DOCUMENTATION}"
)
