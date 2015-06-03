set(ITKBioCell_SRC
itkBioGenome.cxx
itkBioGene.cxx
itkBioGeneNetwork.cxx
itkBioCellBase.cxx
itkBioCellularAggregateBase.cxx
)

add_library(ITKBioCell ${ITKBioCell_SRC})
link_module_dependencies()
itk_module_target(ITKBioCell)
