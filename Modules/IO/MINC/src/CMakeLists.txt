set(ITKIOMINC_SRC
  itkMINCImageIO.cxx
  itkMINCImageIOFactory.cxx
  itkMINCTransformIOFactory.cxx
)

add_library(ITKIOMINC ${ITKIOMINC_SRC})
#target_link_libraries(ITKIOMINC  ${ITKMINC_LIBRARIES} ${ITKIOImageBase_LIBRARIES} ${ITKIOTransformBase_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKIOMINC)
