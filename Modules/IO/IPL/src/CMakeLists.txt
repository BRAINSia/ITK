set(ITKIOIPL_SRC
itkIPLCommonImageIO.cxx
itkIPLFileNameList.cxx
)

add_library(ITKIOIPL ${ITK_LIBRARY_BUILD_TYPE} ${ITKIOIPL_SRC})
link_module_dependencies()
itk_module_target(ITKIOIPL)
