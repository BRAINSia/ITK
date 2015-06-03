if (ITK_USE_GPU)
  set(ITKGPUThresholding_SRC
   )

  set(ITKGPUThresholding_Kernels
    GPUBinaryThresholdImageFilter.cl
    )

  write_gpu_kernels("${ITKGPUThresholding_Kernels}" ITKGPUThresholding_SRC)

  add_library(ITKGPUThresholding ${ITKGPUThresholding_SRC})
  link_module_dependencies()
  itk_module_target(ITKGPUThresholding)
endif()
