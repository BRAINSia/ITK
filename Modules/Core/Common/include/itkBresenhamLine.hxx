/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkBresenhamLine_hxx
#define itkBresenhamLine_hxx

#include "itkPoint.h"
#include "itkMath.h"

#include <algorithm>
#include <iterator>

namespace itk
{
template <unsigned int VDimension>
auto
BresenhamLine<VDimension>::BuildLine(LType Direction, IdentifierType length) -> OffsetArray
{
  // copied from the line iterator
  /** Variables that drive the Bresenham-Algorithm */

  Direction.Normalize();

  // The dimension with the largest absolute component
  const unsigned int maxDistanceDimension = std::distance(
    Direction.Begin(), std::max_element(Direction.Begin(), Direction.End(), [](const auto a, const auto b) {
      return itk::Math::Absolute(a) < itk::Math::Absolute(b);
    }));

  // compute actual line length because the shorter distance
  // the larger deviation due to rounding to integers
  const IdentifierType mainDirectionLen = length - 1;
  const float          euclideanLineLen = mainDirectionLen / itk::Math::Absolute(Direction[maxDistanceDimension]);

  // we are going to start at 0
  constexpr IndexType StartIndex{ 0 };
  IndexType           LastIndex;
  for (unsigned int i = 0; i < VDimension; ++i)
  {
    // round to closest voxel center to minimize the deviation from Direction
    LastIndex[i] = Math::RoundHalfIntegerUp<IndexValueType>(euclideanLineLen * Direction[i]);
  }

  const IndexValueType maxDistance = static_cast<long>(itk::Math::Absolute(LastIndex[maxDistanceDimension]));
  // Increment for the error for each step. Two times the difference between
  // start and end
  IndexType incrementError;

  // Direction of increment. -1 or 1
  IndexType overflowIncrement;
  for (unsigned int i = 0; i < VDimension; ++i)
  {
    auto distance = static_cast<long>(itk::Math::Absolute(LastIndex[i]));
    incrementError[i] = 2 * distance;
    overflowIncrement[i] = (LastIndex[i] < 0 ? -1 : 1);
  }

  // The dimension with the largest difference between start and end
  const unsigned int mainDirection = maxDistanceDimension;
  // If enough is accumulated for a dimension, the index has to be
  // incremented. Will be the number of pixels in the line
  auto maximalError = MakeFilled<IndexType>(maxDistance);
  // After an overflow, the accumulated error is reduced again. Will be
  // two times the number of pixels in the line
  auto reduceErrorAfterIncrement = MakeFilled<IndexType>(2 * maxDistance);
  // Accumulated error for the other dimensions
  auto accumulateError = MakeFilled<IndexType>(0);

  OffsetArray result(length);
  auto        currentImageIndex = MakeFilled<IndexType>(0);
  result[0] = currentImageIndex - StartIndex;
  unsigned int steps = 1;
  while (steps < length)
  {
    // This part is from ++ in LineConstIterator
    // We need to modify accumulateError, currentImageIndex, isAtEnd
    for (unsigned int i = 0; i < VDimension; ++i)
    {
      if (i == mainDirection)
      {
        currentImageIndex[i] += overflowIncrement[i];
      }
      else
      {
        accumulateError[i] += incrementError[i];
        if (accumulateError[i] >= maximalError[i])
        {
          currentImageIndex[i] += overflowIncrement[i];
          accumulateError[i] -= reduceErrorAfterIncrement[i];
        }
      }
    }

    result[steps] = currentImageIndex - StartIndex; // produce an offset

    ++steps;
  }
  return result;
}

template <unsigned int VDimension>
auto
BresenhamLine<VDimension>::BuildLine(IndexType p0, IndexType p1) -> IndexArray
{
  // Integer-only N-dimensional Bresenham, guaranteeing exact start and end
  // points. This avoids floating-point direction conversion entirely.
  // Reference: classic Bresenham extended to N-D as used by scikit-image,
  // OpenCV, and VTK.

  // Compute displacements and find the dominant axis
  IndexType      delta;
  IndexType      step; // +1 or -1 per dimension
  IndexValueType maxAbsDelta = 0;
  unsigned int   mainAxis = 0;
  for (unsigned int i = 0; i < VDimension; ++i)
  {
    delta[i] = p1[i] - p0[i];
    step[i] = (delta[i] >= 0) ? 1 : -1;
    const auto absDelta = static_cast<IndexValueType>(itk::Math::Absolute(delta[i]));
    if (absDelta > maxAbsDelta)
    {
      maxAbsDelta = absDelta;
      mainAxis = i;
    }
  }

  // Number of pixels = steps along dominant axis + 1
  const IdentifierType numPixels = static_cast<IdentifierType>(maxAbsDelta) + 1;

  IndexArray indices;
  indices.reserve(numPixels);

  // Error accumulators for each secondary axis (2 * |delta[i]| per step,
  // overflow when accumulated error >= maxAbsDelta)
  auto accumulateError = MakeFilled<IndexType>(0);
  auto currentIndex = p0;

  for (IdentifierType s = 0; s < numPixels; ++s)
  {
    indices.push_back(currentIndex);

    // Advance along each dimension
    for (unsigned int i = 0; i < VDimension; ++i)
    {
      if (i == mainAxis)
      {
        currentIndex[i] += step[i];
      }
      else
      {
        accumulateError[i] += 2 * static_cast<IndexValueType>(itk::Math::Absolute(delta[i]));
        if (accumulateError[i] >= maxAbsDelta)
        {
          currentIndex[i] += step[i];
          accumulateError[i] -= 2 * maxAbsDelta;
        }
      }
    }
  }

  return indices;
}

} // namespace itk

#endif
