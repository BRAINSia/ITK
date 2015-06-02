set(ITKIOTransformInsightLegacy_SRC
itkTxtTransformIOFactory.cxx
)

add_library(ITKIOTransformInsightLegacy ${ITKIOTransformInsightLegacy_SRC})
#target_link_libraries(ITKIOTransformInsightLegacy
#  ${ITKIOTransformBase_LIBRARIES} ${ITKDoubleConversion_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKIOTransformInsightLegacy)
