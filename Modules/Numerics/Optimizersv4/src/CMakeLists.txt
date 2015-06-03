set(ITKOptimizersv4_SRC
  itkSingleValuedNonLinearVnlOptimizerv4.cxx
  itkSingleValuedVnlCostFunctionAdaptorv4.cxx
  itkLBFGSOptimizerv4.cxx
  itkLBFGSBOptimizerv4.cxx
  itkAmoebaOptimizerv4.cxx
  )

add_library(ITKOptimizersv4 ${ITKOptimizersv4_SRC})
link_module_dependencies()
itk_module_target(ITKOptimizersv4)
