set(ITKVtkGlue_SRCS
QuickView.cxx
)

# VTK 5.8 and greater defines VTK_LIBRARIES
if(NOT VTK_LIBRARIES)
  set(ITKVtkGlue_VTK_LIBRARIES_EXPLICIT vtkIO;vtkHybrid;vtkVolumeRendering)
endif()

### generating libraries
add_library( ITKVtkGlue ${ITKVtkGlue_SRCS})
link_module_dependencies()
itk_module_target(ITKVtkGlue)
