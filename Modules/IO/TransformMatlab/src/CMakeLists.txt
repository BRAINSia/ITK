set(ITKIOTransformMatlab_SRC
itkMatlabTransformIOFactory.cxx
)

add_library(ITKIOTransformMatlab ${ITKIOTransformMatlab_SRC})
#target_link_libraries(ITKIOTransformMatlab ${ITKIOTransformBase_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKIOTransformMatlab)
