set(ITKIOTransformMatlab_SRC
itkMatlabTransformIOFactory.cxx
)

add_library(ITKIOTransformMatlab ${ITKIOTransformMatlab_SRC})
link_module_dependencies()
itk_module_target(ITKIOTransformMatlab)
