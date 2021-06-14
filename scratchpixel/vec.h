#include <cmath>
#include <iostream>
template <typename T>
class Vec {
 public:
  Vec() : x(1.f), y(0.f), z(0.f) { std::cout << "initial function"; }
  Vec(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
  Vec(const T& other_vec) : Vec(other_vec.x, other_vec.y, other_vec.z) {}
  T x, y, z;

  T length() {
    std::cout << x * x + y * y + z * z << std::endl;
    return sqrt(x * x + y * y + z * z);
  }

  T norm() { return length(); }

  T magnitude() { return length(); }

  Vec<T>& normalize() {
    T len = length();
    if (len > 0) {
      T invlen = 1.0 / len;
      x *= invlen;
      y *= invlen;
      z *= invlen;
    }
    return *this;
  }

  bool operator==(const Vec<T>& b) const {
    return x == b.x and y == b.y and z == b.z;
  }

  T dot(const Vec<T>& b) { return x * b.x + y * b.y + z * b.z; }

  Vec<T> cross(const Vec<T> b) {
    return Vec<T>(y * b.z - z * b.y, z * b.x - x * b.z,
                  x * b.y - y * b.x);
  }
};

typedef Vec<double> Vec3;

template <typename T>
T length(const Vec<T>& V) {
  return sqrt(V.x * V.x + V.y * V.y + V.z * V.z);
}

template <typename T>
Vec<T> normalize(Vec<T>& V) {
  double len = length(V);
  double invlen = 1.0 / len;
  V.x *= invlen;
  V.y *= invlen;
  V.z *= invlen;
  return V;
}

template <typename T>
T dot(const Vec<T>& a, const Vec<T>& b) {
  return a.x * b.x + a.y * b.y + a.z + b.z;
}

template <typename T>
bool operator==(const Vec<T>& a, const Vec<T>& b) {
  return a.x == b.x and a.y == b.y and a.z == b.z;
}

template <typename T>
Vec<T> cross(const Vec<T> &a,const Vec<T> &b)
{
  return Vec<T>(
    a.y*b.z + b.y*a.z,
    a.z*b.x + b.z*a.x,
    a.x*b.y + b.x*a.y
  );
}