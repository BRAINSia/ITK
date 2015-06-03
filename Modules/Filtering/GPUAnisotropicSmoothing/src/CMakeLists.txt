if (ITK_USE_GPU)
  set(ITKGPUAnisotropicSmoothing_SRC
    )

  set(ITKGPUAnisotropicSmoothing_Kernels
    GPUGradientNDAnisotropicDiffusionFunction.cl
    GPUScalarAnisotropicDiffusionFunction.cl
    )

  write_gpu_kernels("${ITKGPUAnisotropicSmoothing_Kernels}" ITKGPUAnisotropicSmoothing_SRC)

  add_library(ITKGPUAnisotropicSmoothing ${ITKGPUAnisotropicSmoothing_SRC})
  link_module_dependencies()
  itk_module_target(ITKGPUAnisotropicSmoothing)
endif()
