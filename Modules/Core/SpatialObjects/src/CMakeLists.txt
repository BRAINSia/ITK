set(ITKSpatialObjects_SRC
itkMetaEvent.cxx
itkCylinderSpatialObject.cxx
itkSpatialObjectFactoryBase.cxx
itkArrowSpatialObject.cxx
)

add_library(ITKSpatialObjects ${ITKSpatialObjects_SRC})
link_module_dependencies()
itk_module_target(ITKSpatialObjects)
