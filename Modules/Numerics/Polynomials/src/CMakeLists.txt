set(ITKPolynomials_SRC
itkMultivariateLegendrePolynomial.cxx
)

add_library(ITKPolynomials ${ITKPolynomials_SRC})
#target_link_libraries(ITKPolynomials  ${ITKCommon_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKPolynomials)
