if(ITK_TEMPLATE_EXPLICIT_INSTANTIATION)
  file(GLOB ITK_ITKIOCSV_EXPLICIT_SOURCES "*Explicit.cxx")
endif()

set(ITKIOCSV_SRC
itkCSVFileReaderBase.cxx
${ITK_ITKIOCSV_EXPLICIT_SOURCES}
)

add_library(ITKIOCSV ${ITK_LIBRARY_BUILD_TYPE} ${ITKIOCSV_SRC})
itk_module_link_dependencies()
itk_module_target(ITKIOCSV)
