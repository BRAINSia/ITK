set(ITKIOMINC_SRC
  itkMINCImageIO.cxx
  itkMINCImageIOFactory.cxx
  itkMINCTransformIOFactory.cxx
)

add_library(ITKIOMINC ${ITKIOMINC_SRC})
link_module_dependencies()
itk_module_target(ITKIOMINC)
