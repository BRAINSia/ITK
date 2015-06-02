set(ITKIOGIPL_SRC
itkGiplImageIOFactory.cxx
itkGiplImageIO.cxx
)

add_library(ITKIOGIPL ${ITK_LIBRARY_BUILD_TYPE} ${ITKIOGIPL_SRC})
#target_link_libraries(ITKIOGIPL  ${ITKIOImageBase_LIBRARIES} ${ITKZLIB_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKIOGIPL)
