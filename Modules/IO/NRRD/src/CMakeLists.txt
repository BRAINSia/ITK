set(ITKIONRRD_SRC
itkNrrdImageIOFactory.cxx
itkNrrdImageIO.cxx
)

add_library(ITKIONRRD ${ITK_LIBRARY_BUILD_TYPE} ${ITKIONRRD_SRC})
#target_link_libraries(ITKIONRRD  ${ITKNrrdIO_LIBRARIES} ${ITKIOImageBase_LIBRARIES})
link_module_dependencies()
itk_module_target(ITKIONRRD)
