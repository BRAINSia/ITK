set(ITKIOTransformHDF5_SRC
itkHDF5TransformIO.cxx
itkHDF5TransformIOFactory.cxx
)

add_library(ITKIOTransformHDF5 ${ITKIOTransformHDF5_SRC})
link_module_dependencies()
itk_module_target(ITKIOTransformHDF5)
