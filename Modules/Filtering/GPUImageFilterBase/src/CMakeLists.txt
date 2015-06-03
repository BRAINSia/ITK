if (ITK_USE_GPU)
  set(ITKGPUImageFilterBase_SRC
    )

  set(ITKGPUImageFilterBase_Kernels
    GPUNeighborhoodOperatorImageFilter.cl
    )

  write_gpu_kernels("${ITKGPUImageFilterBase_Kernels}" ITKGPUImageFilterBase_SRC)

  add_library(ITKGPUImageFilterBase ${ITKGPUImageFilterBase_SRC})
  link_module_dependencies()
  itk_module_target(ITKGPUImageFilterBase)
endif()
