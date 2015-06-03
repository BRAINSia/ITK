set(ITKIOCSV_SRC
itkCSVFileReaderBase.cxx
)

add_library(ITKIOCSV ${ITKIOCSV_SRC})
link_module_dependencies()
itk_module_target(ITKIOCSV)
