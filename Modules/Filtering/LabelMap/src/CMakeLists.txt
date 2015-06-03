set(ITKLabelMap_SRCS
itkGeometryUtilities.cxx
)
### generating libraries
add_library( ITKLabelMap ${ITKLabelMap_SRCS})
link_module_dependencies()
itk_module_target(ITKLabelMap)
