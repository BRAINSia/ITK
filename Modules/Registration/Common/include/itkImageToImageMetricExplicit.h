#ifndef itkImageToImageMetricExplicit_h
#define itkImageToImageMetricExplicit_h

#include "ITKRegistrationCommonExport.h"

extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<unsigned int, 2u>, itk::Image<unsigned int, 2u> >; //Instantiated 6 times
extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<float, 3u>, itk::Image<char, 3u> >; //Instantiated 6 times
extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<double, 2u>, itk::Image<double, 2u> >; //Instantiated 33 times
extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<short, 3u>, itk::Image<short, 3u> >; //Instantiated 24 times
extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<unsigned short, 2u>, itk::Image<unsigned short, 2u> >; //Instantiated 18 times
extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<short, 2u>, itk::Image<short, 2u> >; //Instantiated 6 times
extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<int, 2u>, itk::Image<int, 2u> >; //Instantiated 6 times
extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<float, 2u>, itk::Image<float, 2u> >; //Instantiated 78 times
extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<float, 3u>, itk::Image<float, 3u> >; //Instantiated 33 times
extern template class ITKRegistrationCommon_EXPORT itk::ImageToImageMetric<itk::Image<unsigned char, 2u>, itk::Image<unsigned char, 2u> >; //Instantiated 48 times
#endif //itkImageToImageMetricExplicit_h
