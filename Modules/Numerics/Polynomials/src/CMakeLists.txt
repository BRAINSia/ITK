set(ITKPolynomials_SRC
itkMultivariateLegendrePolynomial.cxx
)

add_library(ITKPolynomials ${ITKPolynomials_SRC})
link_module_dependencies()
itk_module_target(ITKPolynomials)
