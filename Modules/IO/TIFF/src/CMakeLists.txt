set(ITKIOTIFF_SRC
itkTIFFImageIO.cxx
itkTIFFReaderInternal.cxx
itkTIFFImageIOFactory.cxx
)

add_library(ITKIOTIFF ${ITK_LIBRARY_BUILD_TYPE} ${ITKIOTIFF_SRC})
link_module_dependencies()
itk_module_target(ITKIOTIFF)
