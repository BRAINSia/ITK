set(ITKMesh_SRC
itkMeshRegion.cxx
itkSimplexMeshGeometry.cxx
)

add_library(ITKMesh ${ITKMesh_SRC})
#target_link_libraries(ITKMesh  ${ITKTransform_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKMesh)
