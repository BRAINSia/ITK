set(ITKIOJPEG_SRC
itkJPEGImageIOFactory.cxx
itkJPEGImageIO.cxx
)

add_library(ITKIOJPEG ${ITK_LIBRARY_BUILD_TYPE} ${ITKIOJPEG_SRC})
link_module_dependencies()
itk_module_target(ITKIOJPEG)
