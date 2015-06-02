set(DOCUMENTATION "This modules provides code to perform finite element
analysis.  A structural mechanics finite element model can, for instance, be
used for image registration.")

itk_module(ITKFEM
  DEPENDS
    ITKImageFunction
    ITKRegistrationCommon
  USE_DEPENDS
    ITKSpatialObjects
    ITKIOSpatialObjects
  LINK_DEPENDS
    ${ITKMetaIO_LIBRARIES}
  TEST_DEPENDS
    ITKTestKernel
    ITKIOSpatialObjects
  DESCRIPTION
    "${DOCUMENTATION}"
)

# ITKIOSpatialObjects dependency added for itkFEMSpatialObjectWriter
