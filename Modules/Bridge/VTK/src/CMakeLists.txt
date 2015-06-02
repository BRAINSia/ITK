set(ITKVTK_SRC
itkVTKImageExportBase.cxx
)

add_library(ITKVTK ${ITKVTK_SRC})
#target_link_libraries(ITKVTK  ${ITKCommon_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKVTK)
