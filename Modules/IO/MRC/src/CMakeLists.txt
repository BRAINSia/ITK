set(ITKIOMRC_SRC
itkMRCHeaderObject.cxx
itkMRCImageIO.cxx
itkMRCImageIOFactory.cxx
)

add_library(ITKIOMRC ${ITKIOMRC_SRC})
link_module_dependencies()
itk_module_target(ITKIOMRC)
