#ifndef __H_MATH__
#define __H_MATH__

#include "vec.h"

#include <iostream>
#include <cmath>

template <typename T>
class Mat44
{
public:
  Mat44(){};
  Mat44(T m00 ,T m01, T m02,T m10, T m11, T m12, T m20, T m21, T m22){
    m[0][0] = m00;
    m[0][1] = m01;
    m[0][2] = m02;
    m[1][0] = m10;
    m[1][1] = m11;
    m[1][2] = m12;
    m[2][0] = m20;
    m[2][1] = m21;
    m[2][2] = m22;
  }


  const T *operator[](uint8_t i) const { return m[i]; }
  T *operator[](uint8_t i) { return m[i]; }
  T m[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  Mat44 operator*(const Mat44 &rhs) const
  {
    Mat44 mult;
    for (uint8_t i = 0; i < 4; i++)
    {
      for (uint8_t j = 0; j < 4; j++)
      {
        mult[i][j] = m[i][0] * rhs[0][j] + m[i][1] * rhs[1][j] + m[i][2] * rhs[2][j] +
                     m[i][3] * rhs[3][j];
      }
    }
    return mult;
  }

  bool operator==(const Mat44<T> &b) const
  {
    for (uint8_t i = 0; i < 4; i++)
    {
      for (uint8_t j = 0; j < 4; j++)
      {
        if (std::abs(m[i][j] - b[i][j]) > 0.1)
          return false;
      }
    }
    return true;
  }

  Mat44 transpose() const
  {
    Mat44 transpMat;
    for (uint8_t i = 0; i < 4; i++)
    {
      for (uint8_t j = 0; j < 4; j++)
      {
        transpMat[i][j] = m[j][i];
      }
    }
    return transpMat;
  }

  Mat44 inverse() const
  {
    /// A(-1) = C(T)/|A|
    double det = m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) - 
                 m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                 m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    
    double invdet = 1/det;
    
    Mat44 minv;
    minv[0][0] =  (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * invdet;
    minv[1][0] = -(m[1][0] * m[2][2] - m[1][2] * m[2][0]) * invdet;
    minv[2][0] =  (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * invdet;
    minv[0][1] = -(m[0][1] * m[2][2] - m[0][2] * m[2][1]) * invdet;
    minv[1][1] =  (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * invdet;
    minv[2][1] = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]) * invdet;
    minv[0][2] =  (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * invdet;
    minv[1][2] = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]) * invdet;
    minv[2][2] =  (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * invdet;
    return minv;
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &cout, Mat44<T> m)
{
  for (int i = 0; i != 4; i++)
  {
    for (int j = 0; j != 4; j++)
    {
      cout << m[i][j] << ",";
    }
    cout << std::endl;
  }
  return cout;
}

typedef Mat44<double> Mat44f;

////////////////////////////////////////////////////////////////
/// math operation
////////////////////////////////////////////////////////////////

template <typename T>
Vec<T> pntdot(const Vec<T> &vec, const Mat44<T> &mat)
{

  auto ret = Vec<T>(vec.x * mat[0][0] + vec.y * mat[1][0] + vec.z * mat[2][0] + mat[3][0],
                    vec.x * mat[0][1] + vec.y * mat[1][1] + vec.z * mat[2][1] + mat[3][1],
                    vec.x * mat[0][2] + vec.y * mat[1][2] + vec.z * mat[2][2] + mat[3][2]);
  T w = vec.x * mat[0][3] + vec.y * mat[1][3] + vec.z * mat[2][3] + mat[3][3];
  if (w != 1 or w != 0)
  {
    ret.x /= w;
    ret.y /= w;
    ret.z /= w;
  }
  return ret;
}

template <typename T>
Vec<T> dirdot(const Vec<T> &vec, const Mat44<T> &mat)
{
  auto ret = Vec<T>(vec.x * mat[0][0] + vec.y * mat[1][0] + vec.z * mat[2][0],
                    vec.x * mat[0][1] + vec.y * mat[1][1] + vec.z * mat[2][1],
                    vec.x * mat[0][2] + vec.y * mat[1][2] + vec.z * mat[2][2]);
  return ret;
}

#endif