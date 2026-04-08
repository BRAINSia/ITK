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

#include "itkBresenhamLine.h"
#include "itkGTest.h"

#include <iostream>

TEST(BresenhamLine, BuildLineFromVector)
{
  // Test BuildLine(Vector, distance)
  itk::Vector<float, 2> v;
  v[0] = 1;
  v[1] = 1;

  itk::BresenhamLine<2>       line;
  std::vector<itk::Offset<2>> offsets = line.BuildLine(v, 4);

  EXPECT_EQ(offsets.size(), 4u);

  for (int i = 0; i < 4; ++i)
  {
    const itk::Offset<2> expectedOffset{ { i, i } };
    ITK_EXPECT_VECTOR_NEAR(offsets[i], expectedOffset, 0);
  }
}

TEST(BresenhamLine, BuildLineFromIndices)
{
  // Test BuildLine(Index, Index)
  itk::Index<2> p0;
  p0[0] = 0;
  p0[1] = 0;

  itk::Index<2> p1;
  p1[0] = 39;
  p1[1] = 39;

  itk::BresenhamLine<2>      line;
  std::vector<itk::Index<2>> indices = line.BuildLine(p0, p1);

  EXPECT_EQ(indices.size(), 40u);

  for (int i = 0; i < 40; ++i)
  {
    const itk::Index<2> expectedIndex{ { i, i } };
    ITK_EXPECT_VECTOR_NEAR(indices[i], expectedIndex, 0);
  }

  std::cout << "Test Passed !" << std::endl;
}

TEST(BresenhamLine, FinishAtEndIndex)
{
  // Test BuildLine(Index, Index) to finish at the specified end index
  const itk::Index<3> start{ { 0, 0, 0 } }, end{ { 250, 250, 1 } };

  itk::BresenhamLine<3>            line;
  const std::vector<itk::Index<3>> indices = line.BuildLine(start, end);
  EXPECT_EQ(indices.back(), end);
}

TEST(BresenhamLine, FinishAtEndIndexNegativeDirection)
{
  // Test BuildLine(Index, Index) with reversed endpoints (negative direction)
  const itk::Index<3> start{ { 250, 250, 1 } }, end{ { 0, 0, 0 } };

  itk::BresenhamLine<3>            line;
  const std::vector<itk::Index<3>> indices = line.BuildLine(start, end);
  EXPECT_EQ(indices.front(), start);
  EXPECT_EQ(indices.back(), end);
}

TEST(BresenhamLine, AxisAligned2D)
{
  // Horizontal and vertical lines must hit exact endpoints
  itk::BresenhamLine<2> line;

  const auto horiz = line.BuildLine(itk::Index<2>{ { 0, 5 } }, itk::Index<2>{ { 10, 5 } });
  EXPECT_EQ(horiz.size(), 11u);
  EXPECT_EQ(horiz.front(), (itk::Index<2>{ { 0, 5 } }));
  EXPECT_EQ(horiz.back(), (itk::Index<2>{ { 10, 5 } }));
  for (const auto & idx : horiz)
  {
    EXPECT_EQ(idx[1], 5);
  }

  const auto vert = line.BuildLine(itk::Index<2>{ { 3, 0 } }, itk::Index<2>{ { 3, 7 } });
  EXPECT_EQ(vert.size(), 8u);
  EXPECT_EQ(vert.front(), (itk::Index<2>{ { 3, 0 } }));
  EXPECT_EQ(vert.back(), (itk::Index<2>{ { 3, 7 } }));
  for (const auto & idx : vert)
  {
    EXPECT_EQ(idx[0], 3);
  }
}

TEST(BresenhamLine, SinglePixelLine)
{
  // p0 == p1: line should contain exactly one pixel
  itk::BresenhamLine<3> line;
  const itk::Index<3>   p{ { 5, 10, 15 } };

  const auto indices = line.BuildLine(p, p);
  EXPECT_EQ(indices.size(), 1u);
  EXPECT_EQ(indices[0], p);
}

TEST(BresenhamLine, Connectivity2D)
{
  // Every consecutive pair must be 8-connected (Chebyshev distance <= 1)
  itk::BresenhamLine<2> line;
  const auto            indices = line.BuildLine(itk::Index<2>{ { 0, 0 } }, itk::Index<2>{ { 100, 37 } });

  for (size_t i = 1; i < indices.size(); ++i)
  {
    itk::IndexValueType maxStep = 0;
    for (unsigned int d = 0; d < 2; ++d)
    {
      const auto s = static_cast<itk::IndexValueType>(itk::Math::Absolute(indices[i][d] - indices[i - 1][d]));
      if (s > maxStep)
      {
        maxStep = s;
      }
    }
    EXPECT_LE(maxStep, 1) << "Gap between pixels " << i - 1 << " and " << i;
  }
}

TEST(BresenhamLine, Connectivity3D)
{
  // Every consecutive pair must be 26-connected (Chebyshev distance <= 1)
  itk::BresenhamLine<3> line;
  const auto            indices = line.BuildLine(itk::Index<3>{ { 0, 0, 0 } }, itk::Index<3>{ { 50, 80, 30 } });

  for (size_t i = 1; i < indices.size(); ++i)
  {
    itk::IndexValueType maxStep = 0;
    for (unsigned int d = 0; d < 3; ++d)
    {
      const auto s = static_cast<itk::IndexValueType>(itk::Math::Absolute(indices[i][d] - indices[i - 1][d]));
      if (s > maxStep)
      {
        maxStep = s;
      }
    }
    EXPECT_LE(maxStep, 1) << "Gap between pixels " << i - 1 << " and " << i;
  }
}

TEST(BresenhamLine, PixelCountMatchesChebyshev)
{
  // Number of pixels should be Chebyshev distance + 1
  itk::BresenhamLine<3> line;

  struct TestCase
  {
    itk::Index<3> p0, p1;
  };
  const TestCase cases[] = { { { { 0, 0, 0 } }, { { 10, 0, 0 } } },
                             { { { 0, 0, 0 } }, { { 10, 10, 0 } } },
                             { { { 0, 0, 0 } }, { { 10, 10, 10 } } },
                             { { { 0, 0, 0 } }, { { 100, 50, 25 } } },
                             { { { 5, 5, 5 } }, { { 5, 5, 5 } } } };

  for (const auto & tc : cases)
  {
    itk::IndexValueType chebyshev = 0;
    for (unsigned int d = 0; d < 3; ++d)
    {
      const auto dist = static_cast<itk::IndexValueType>(itk::Math::Absolute(tc.p1[d] - tc.p0[d]));
      if (dist > chebyshev)
      {
        chebyshev = dist;
      }
    }
    const auto indices = line.BuildLine(tc.p0, tc.p1);
    EXPECT_EQ(indices.size(), static_cast<size_t>(chebyshev + 1));
  }
}

TEST(BresenhamLine, ReverseSymmetry)
{
  // Forward and reverse lines must have same length and hit same endpoints
  itk::BresenhamLine<3> line;
  const itk::Index<3>   a{ { 10, 20, 3 } }, b{ { 200, 50, 80 } };

  const auto forward = line.BuildLine(a, b);
  const auto reverse = line.BuildLine(b, a);

  EXPECT_EQ(forward.size(), reverse.size());
  EXPECT_EQ(forward.front(), a);
  EXPECT_EQ(forward.back(), b);
  EXPECT_EQ(reverse.front(), b);
  EXPECT_EQ(reverse.back(), a);
}

TEST(BresenhamLine, SteepDiagonal3D)
{
  // Strongly diagonal line that triggered the original bug
  itk::BresenhamLine<3> line;
  const itk::Index<3>   start{ { 0, 0, 0 } }, end{ { 250, 250, 1 } };

  const auto fwd = line.BuildLine(start, end);
  EXPECT_EQ(fwd.front(), start);
  EXPECT_EQ(fwd.back(), end);

  const auto rev = line.BuildLine(end, start);
  EXPECT_EQ(rev.front(), end);
  EXPECT_EQ(rev.back(), start);

  EXPECT_EQ(fwd.size(), rev.size());
}
