set(ITKIOSpatialObjects_SRC
itkPolygonGroupSpatialObjectXMLFile.cxx
)

add_library(ITKIOSpatialObjects ${ITKIOSpatialObjects_SRC})
link_module_dependencies()
itk_module_target(ITKIOSpatialObjects)
