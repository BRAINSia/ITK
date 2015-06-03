set(ITKVideoBridgeVXL_SRC
itkVXLVideoIO.cxx
itkVXLVideoIOFactory.cxx
)

add_library(ITKVideoBridgeVXL ${ITKVideoBridgeVXL_SRC})
link_module_dependencies()
itk_module_target(ITKVideoBridgeVXL)
