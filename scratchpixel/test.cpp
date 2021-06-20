#include <gtest/gtest.h>
#include "vec.h"
#include "mat.h"

// gtest document : https://google.github.io/googletest/primer.html
// Demonstrate some basic assertions.
TEST(VectorClass, InitializeAVector) {
  typedef Vec<double> vec3;
  Vec<double> a = Vec<double>();
  std::cout << "abc";
  ASSERT_EQ(a.x, 1);
  // vec3 b();// 会被当成函数声明
  // ASSERT_EQ(b.x,1); 因此這個不用管
  vec3 c(1, 2, 3);
  ASSERT_EQ(c.x, 1);
}

TEST(VectorClass, TestLength) {
  Vec3 a(1, 2, 3);
  ASSERT_EQ(length(a), sqrt(14));
  ASSERT_EQ(a.length(), sqrt(14));
  ASSERT_EQ(a.norm(), sqrt(14));
  ASSERT_EQ(a.magnitude(), sqrt(14));
}

TEST(VectorClass, TestNormalize) {
  Vec3 a(1, 0, 0);
  ASSERT_EQ(normalize(a), Vec3(1, 0, 0));
  ASSERT_EQ(a.normalize(), Vec3(1, 0, 0));

  Vec3 b(0, 2, 0);
  ASSERT_EQ(normalize(b), Vec3(0, 1, 0));
  ASSERT_EQ(b.normalize(), Vec3(0, 1, 0));
}

TEST(VectorClass, TestDot) {
  Vec3 a(1, 0, 0);
  Vec3 b(1, 0, 0);
  ASSERT_EQ(a.dot(b), 1.f);
  ASSERT_EQ(dot(a, b), 1.f);

  Vec3 c(2, 2, 0);
  ASSERT_EQ(a.dot(c), 2.f);
  ASSERT_EQ(dot(a, c), 2.f);
}

TEST(VectorClass, AddSubMul)
{
  Vec3 a(1, 2, 3);
  Vec3 b(3, 2, 1);
  ASSERT_EQ(a+b,Vec3(4,4,4));
  ASSERT_EQ(a-b,Vec3(-2,0,2));
  ASSERT_EQ(a*2,Vec3(2,4,6));
  ASSERT_EQ(2*a,Vec3(2,4,6));
}

TEST(MatrixClass, Mul)
{
  Mat44f a;
  Mat44f b;
  Mat44f c;
  a[0][0] = 2;
  b[0][0] = 2;
  c[0][0] = 4;
  ASSERT_EQ(a*b,c);
}


