set(ITKVTK_SRC
itkVTKImageExportBase.cxx
)

add_library(ITKVTK ${ITKVTK_SRC})
link_module_dependencies()
itk_module_target(ITKVTK)
