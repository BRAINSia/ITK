set(ITKIOTransformBase_SRC
itkTransformFactoryBase.cxx
itkTransformFileWriterSpecializations.cxx
)

add_library(ITKIOTransformBase ${ITKIOTransformBase_SRC})
#target_link_libraries(ITKIOTransformBase ${ITKTransform_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKIOTransformBase)
