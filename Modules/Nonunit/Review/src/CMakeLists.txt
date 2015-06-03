set(ITKReview_SRC
itkBruker2DSEQImageIO.cxx
itkBruker2DSEQImageIOFactory.cxx
itkJPEG2000ImageIO.cxx
itkJPEG2000ImageIOFactory.cxx
itkVoxBoCUBImageIO.cxx
itkVoxBoCUBImageIOFactory.cxx
)

add_library(ITKReview ${ITKReview_SRC})
link_module_dependencies()
itk_module_target(ITKReview)


