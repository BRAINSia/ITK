set(ITKMesh_SRC
itkMeshRegion.cxx
itkSimplexMeshGeometry.cxx
)

add_library(ITKMesh ${ITKMesh_SRC})
link_module_dependencies()
itk_module_target(ITKMesh)
