set(ITKSpatialObjects_SRC
itkMetaEvent.cxx
itkCylinderSpatialObject.cxx
itkSpatialObjectFactoryBase.cxx
itkArrowSpatialObject.cxx
)

add_library(ITKSpatialObjects ${ITK_LIBRARY_BUILD_TYPE} ${ITKSpatialObjects_SRC})
itk_module_link_dependencies()
itk_module_target(ITKSpatialObjects)
