#include<cmath>
template <typename T>
class Mat44 {
 public:
  Mat44(){};
  const T* operator[](uint8_t i) const { return m[i]; }
  T* operator[](uint8_t i) { return m[i]; }
  T m[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
  Mat44 operator*(const Mat44& rhs) const 
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

  bool operator==(const Mat44<T>& b) const {
    for (uint8_t i = 0; i < 4; i++) {
      for (uint8_t j = 0; j < 4; j++) {
        if (std::abs(m[i][j] - b[i][j])>0.1)
          return false;
      }
    }
    return true;
  }
};

typedef Mat44<float> Mat44f;