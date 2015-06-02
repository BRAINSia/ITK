set(ITKSpatialObjects_SRC
itkMetaEvent.cxx
itkCylinderSpatialObject.cxx
itkSpatialObjectFactoryBase.cxx
itkArrowSpatialObject.cxx
)

add_library(ITKSpatialObjects ${ITKSpatialObjects_SRC})
#target_link_libraries(ITKSpatialObjects  ${ITKImageFunction_LIBRARIES} ${ITKMesh_LIBRARIES} ${ITKIOImageBase_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKSpatialObjects)
