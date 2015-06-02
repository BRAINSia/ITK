set(ITKIOCSV_SRC
itkCSVFileReaderBase.cxx
)

add_library(ITKIOCSV ${ITKIOCSV_SRC})
#target_link_libraries(ITKIOCSV  ${ITKIOImageBase_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKIOCSV)
