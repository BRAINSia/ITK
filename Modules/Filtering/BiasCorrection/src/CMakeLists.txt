set(ITKBiasCorrection_SRC
itkCompositeValleyFunction.cxx
itkCacheableScalarFunction.cxx
)

add_library(ITKBiasCorrection ${ITKBiasCorrection_SRC})
link_module_dependencies()
itk_module_target(ITKBiasCorrection)
