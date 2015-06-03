set(ITKIOBioRad_SRC
itkBioRadImageIOFactory.cxx
itkBioRadImageIO.cxx
)

add_library(ITKIOBioRad ${ITK_LIBRARY_BUILD_TYPE} ${ITKIOBioRad_SRC})
link_module_dependencies()
itk_module_target(ITKIOBioRad)
