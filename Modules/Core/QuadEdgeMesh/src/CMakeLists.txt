set(ITKQuadEdgeMesh_SRC
itkQuadEdge.cxx
)

add_library(ITKQuadEdgeMesh ${ITKQuadEdgeMesh_SRC})
#target_link_libraries(ITKQuadEdgeMesh  ${ITKMesh_LIBRARIES})
link_module_dependencies(ITKQuadEdgeMesh)
itk_module_target(ITKQuadEdgeMesh)
