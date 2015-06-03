set(ITKVideoBridgeOpenCV_SRC
itkOpenCVVideoIO.cxx
itkOpenCVVideoIOFactory.cxx
)

add_library(ITKVideoBridgeOpenCV ${ITKVideoBridgeOpenCV_SRC})
link_module_dependencies()
itk_module_target(ITKVideoBridgeOpenCV)
