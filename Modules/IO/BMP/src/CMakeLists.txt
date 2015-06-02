set(ITKIOBMP_SRC
itkBMPImageIO.cxx
itkBMPImageIOFactory.cxx
)

add_library(ITKIOBMP ${ITK_LIBRARY_BUILD_TYPE} ${ITKIOBMP_SRC})
#target_link_libraries(ITKIOBMP  ${ITKIOImageBase_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKIOBMP)
