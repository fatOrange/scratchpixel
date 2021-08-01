#include <gtest/gtest.h>
#include "vec.h"
#include "mat.h"

// gtest document : https://google.github.io/googletest/primer.html
// scratchpixel : https://www.scratchapixel.com/
// Demonstrate some basic assertions.
TEST(VectorClass, InitializeAVector) {
  Vec<double> a = Vec<double>();
  ASSERT_EQ(a.x, 1);
  // Vec3f b();// 会被当成函数声明
  // ASSERT_EQ(b.x,1); 因此這個不用管
  Vec3f c(1, 2, 3);
  ASSERT_EQ(c.x, 1);
}

TEST(VectorClass, TestLength) {
  Vec3f a(1, 2, 3);
  ASSERT_EQ(length(a), sqrt(14));
  ASSERT_EQ(a.length(), sqrt(14));
  ASSERT_EQ(a.norm(), sqrt(14));
  ASSERT_EQ(a.magnitude(), sqrt(14));
}

TEST(VectorClass, TestNormalize) {
  Vec3f a(1, 0, 0);
  ASSERT_EQ(normalize(a), Vec3f(1, 0, 0));
  ASSERT_EQ(a.normalize(), Vec3f(1, 0, 0));

  Vec3f b(0, 2, 0);
  ASSERT_EQ(normalize(b), Vec3f(0, 1, 0));
  ASSERT_EQ(b.normalize(), Vec3f(0, 1, 0));
}

TEST(VectorClass, TestDot) {
  Vec3f a(1, 0, 0);
  Vec3f b(1, 0, 0);
  ASSERT_EQ(a.dot(b), 1.f);
  ASSERT_EQ(dot(a, b), 1.f);

  Vec3f c(2, 2, 0);
  ASSERT_EQ(a.dot(c), 2.f);
  ASSERT_EQ(dot(a, c), 2.f);
}

TEST(VectorClass, AddSubMul)
{
  Vec3f a(1, 2, 3);
  Vec3f b(3, 2, 1);
  ASSERT_EQ(a+b,Vec3f(4,4,4));
  ASSERT_EQ(a-b,Vec3f(-2,0,2));
  ASSERT_EQ(a*2,Vec3f(2,4,6));
  ASSERT_EQ(2*a,Vec3f(2,4,6));
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

TEST(MatrixClass, point_multiply_matrix)
{
  Mat44f m;
  Vec3f v(1.0f,1.0f,1.0f);
  m[0][0] = 0;
  m[0][1] = 1.0f;
  m[1][0] = -1.0f;
  m[1][1] = 0;
  ASSERT_EQ(pntdot(v,m),Vec3f(-1.0f,1.0f,1.0f));

  Mat44f m2;
  m2[0][0] = 1.f;
  m2[0][1] = 2.f;
  m2[0][2] = 3.f;
  m2[1][0] = 4.f;
  m2[1][1] = 5.f;
  m2[1][2] = 6.f;
  m2[2][0] = -1.f;
  m2[2][1] = 3.f;
  m2[2][2] = 0.f;
  Vec3f v2(1.0,2.0f,3.0f);

  ASSERT_EQ(pntdot(v2,m2),Vec3f(6.0f,21.0f,15.0f));
}

TEST(MatrixClass, direct_multiply_matrix)
{
  Mat44f m;
  Vec3f v(1.0f,1.0f,1.0f);
  m[0][0] = 0;
  m[0][1] = 1.0f;
  m[1][0] = -1.0f;
  m[1][1] = 0;
  ASSERT_EQ(dirdot(v,m),Vec3f(-1.0f,1.0f,1.0f));

  Mat44f m2;
  m2[0][0] = 1.f;
  m2[0][1] = 2.f;
  m2[0][2] = 3.f;
  m2[1][0] = 4.f;
  m2[1][1] = 5.f;
  m2[1][2] = 6.f;
  m2[2][0] = -1.f;
  m2[2][1] = 3.f;
  m2[2][2] = 0.f;
  Vec3f v2(1.0,2.0f,3.0f);

  ASSERT_EQ(dirdot(v2,m2),Vec3f(6.0f,21.0f,15.0f));
}


TEST(MatrixClass, test_mat_transpose)
{
  Mat44f a;
  Mat44f b;
  ASSERT_EQ(a.transpose(),a);
  a[2][1] = 2.4;
  b[1][2] = 2.4;
  a[0][1] = -1.0f;
  b[1][0] = -1.0f;
  ASSERT_EQ(a.transpose(),b);

}

TEST(MatrixClass, test_mat_inverse)
{
  Mat44f a(1,2,3,
           1,5,6,
           17,8,9);
  Mat44f b(1.0f/16.0f,-1.0f/8,1.0f/16,
           -31.0f/16.0f,7.0f/8.0f,1.0f/16.0f,
           77.0f/48,-13.0f/24,-1.0f/16);
  ASSERT_EQ(a.inverse(),b);

}