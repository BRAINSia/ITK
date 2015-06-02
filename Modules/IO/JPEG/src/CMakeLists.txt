set(ITKIOJPEG_SRC
itkJPEGImageIOFactory.cxx
itkJPEGImageIO.cxx
)

add_library(ITKIOJPEG ${ITK_LIBRARY_BUILD_TYPE} ${ITKIOJPEG_SRC})
#target_link_libraries(ITKIOJPEG  ${ITKJPEG_LIBRARIES} ${ITKIOImageBase_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKIOJPEG)
