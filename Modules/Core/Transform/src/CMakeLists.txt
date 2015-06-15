if(ITK_TEMPLATE_EXPLICIT_INSTANTIATION)
  file(GLOB ITK_TRANSFORM_EXPLICIT_SOURCES "*Explicit.cxx")
else()
  set(ITK_TRANSFORM_EXPLICIT_SOURCES "")
endif()

set(ITKTransform_SRC
itkTransformBase.cxx
${ITK_TRANSFORM_EXPLICIT_SOURCES}
)

add_library(ITKTransform ${ITK_LIBRARY_BUILD_TYPE} ${ITKTransform_SRC})
itk_module_link_dependencies()
itk_module_target(ITKTransform)
