set(ITKQuadEdgeMesh_SRC
itkQuadEdge.cxx
)

add_library(ITKQuadEdgeMesh ${ITKQuadEdgeMesh_SRC})
link_module_dependencies()
itk_module_target(ITKQuadEdgeMesh)
