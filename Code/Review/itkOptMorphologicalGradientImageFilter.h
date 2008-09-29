/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkOptMorphologicalGradientImageFilter.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkOptMorphologicalGradientImageFilter_h
#define __itkOptMorphologicalGradientImageFilter_h

#include "itkKernelImageFilter.h"
#include "itkMovingHistogramMorphologicalGradientImageFilter.h"
#include "itkBasicDilateImageFilter.h"
#include "itkBasicErodeImageFilter.h"
#include "itkAnchorErodeImageFilter.h"
#include "itkAnchorDilateImageFilter.h"
#include "itkVanHerkGilWermanDilateImageFilter.h"
#include "itkVanHerkGilWermanErodeImageFilter.h"
#include "itkSubtractImageFilter.h"
#include "itkConstantBoundaryCondition.h"
#include "itkFlatStructuringElement.h"
#include "itkNeighborhood.h"

namespace itk {

/**
 * \class MorphologicalGradientImageFilter
 * \brief gray scale dilation of an image
 *
 * Dilate an image using grayscale morphology. Dilation takes the
 * maximum of all the pixels identified by the structuring element.
 *
 * The structuring element is assumed to be composed of binary
 * values (zero or one). Only elements of the structuring element
 * having values > 0 are candidates for affecting the center pixel.
 * 
 * \sa MorphologyImageFilter, GrayscaleFunctionDilateImageFilter, BinaryDilateImageFilter
 * \ingroup ImageEnhancement  MathematicalMorphologyImageFilters
 */

template<class TInputImage, class TOutputImage, class TKernel>
class ITK_EXPORT MorphologicalGradientImageFilter : 
    public KernelImageFilter<TInputImage, TOutputImage, TKernel>
{
public:
  /** Standard class typedefs. */
  typedef MorphologicalGradientImageFilter                      Self;
  typedef KernelImageFilter<TInputImage,TOutputImage, TKernel>  Superclass;
  typedef SmartPointer<Self>                                    Pointer;
  typedef SmartPointer<const Self>                              ConstPointer;
  
  /** Standard New method. */
  itkNewMacro(Self);  

  /** Runtime information support. */
  itkTypeMacro(MorphologicalGradientImageFilter, 
               KernelImageFilter);
  
  /** Image related typedefs. */
  itkStaticConstMacro(ImageDimension, unsigned int,
                      TInputImage::ImageDimension);
                      
  /** Image related typedefs. */
  typedef TInputImage                                           InputImageType;
  typedef TOutputImage                                          OutputImageType;
  typedef typename TInputImage::RegionType                      RegionType;
  typedef typename TInputImage::SizeType                        SizeType;
  typedef typename TInputImage::IndexType                       IndexType;
  typedef typename TInputImage::PixelType                       PixelType;
  typedef typename TInputImage::OffsetType                      OffsetType;
  typedef typename Superclass::OutputImageRegionType            OutputImageRegionType;

  typedef FlatStructuringElement< itkGetStaticConstMacro(ImageDimension) >
                                                                FlatKernelType;
  typedef MovingHistogramMorphologicalGradientImageFilter< TInputImage, TOutputImage, TKernel >
                                                                HistogramFilterType;
  typedef BasicDilateImageFilter< TInputImage, TInputImage, TKernel >
                                                                BasicDilateFilterType;
  typedef BasicErodeImageFilter< TInputImage, TInputImage, TKernel >
                                                                BasicErodeFilterType;
  typedef AnchorDilateImageFilter< TInputImage, FlatKernelType >
                                                                AnchorDilateFilterType;
  typedef AnchorErodeImageFilter< TInputImage, FlatKernelType > AnchorErodeFilterType;
  typedef VanHerkGilWermanDilateImageFilter< TInputImage, FlatKernelType >
                                                                VHGWDilateFilterType;
  typedef VanHerkGilWermanErodeImageFilter< TInputImage, FlatKernelType > 
                                                                VHGWErodeFilterType;
  typedef SubtractImageFilter< TInputImage, TInputImage, TOutputImage >
                                                                SubtractFilterType;
  
  /** Kernel typedef. */
  typedef TKernel                                               KernelType;
//   typedef typename KernelType::Superclass KernelSuperClass;
//   typedef Neighborhood< typename KernelType::PixelType, ImageDimension > KernelSuperClass;
  
  /** Set kernel (structuring element). */
  void SetKernel( const KernelType& kernel );

  /** Set/Get the backend filter class. */
  void SetAlgorithm(int algo );
  itkGetMacro(Algorithm, int);
  
  /** MorphologicalGradientImageFilter need to set its internal filters as modified */
  virtual void Modified() const;

  /** define values used to determine which algorithm to use */
  enum {
    BASIC = 0,
    HISTO = 1,
    ANCHOR = 2,
    VHGW = 3
  } AlgorithmChoice;
  

protected:
  MorphologicalGradientImageFilter();
  ~MorphologicalGradientImageFilter() {};
  void PrintSelf(std::ostream& os, Indent indent) const;
  
  void GenerateData();

private:
  MorphologicalGradientImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  // the filters used internally
  typename HistogramFilterType::Pointer    m_HistogramFilter;
  typename BasicDilateFilterType::Pointer  m_BasicDilateFilter;
  typename BasicErodeFilterType::Pointer   m_BasicErodeFilter;
  typename AnchorDilateFilterType::Pointer m_AnchorDilateFilter;
  typename AnchorErodeFilterType::Pointer  m_AnchorErodeFilter;
  typename VHGWDilateFilterType::Pointer   m_VanHerkGilWermanDilateFilter;
  typename VHGWErodeFilterType::Pointer    m_VanHerkGilWermanErodeFilter;

  // and the name of the filter
  int                                      m_Algorithm;

}; // end of class

} // end namespace itk
  
#ifndef ITK_MANUAL_INSTANTIATION
#include "itkOptMorphologicalGradientImageFilter.txx"
#endif

#endif
