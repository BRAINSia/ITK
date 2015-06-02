set(ITKLabelMap_SRCS
itkGeometryUtilities.cxx
)
### generating libraries
add_library( ITKLabelMap ${ITKLabelMap_SRCS})
#target_link_libraries(ITKLabelMap ${ITKStatistics_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKLabelMap)
