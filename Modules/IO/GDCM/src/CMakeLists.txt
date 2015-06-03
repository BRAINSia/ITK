set(ITKIOGDCM_SRC
itkGDCMImageIO.cxx
itkGDCMImageIOFactory.cxx
itkGDCMSeriesFileNames.cxx
)

add_library(ITKIOGDCM ${ITKIOGDCM_SRC})
link_module_dependencies()
itk_module_target(ITKIOGDCM)
