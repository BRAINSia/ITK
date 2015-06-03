set(ITKWatersheds_SRC
itkWatershedMiniPipelineProgressCommand.cxx
itkOneWayEquivalencyTable.cxx
)

add_library(ITKWatersheds ${ITKWatersheds_SRC})
link_module_dependencies()
itk_module_target(ITKWatersheds)
