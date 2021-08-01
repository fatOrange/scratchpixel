#ifndef __H_TRIGONO__
#define __H_TRIGONO__
#include <cmath>
#include <algorithm>
#include "vec.h"
template<typename T>
Vec3<T> spericalToCartesian(const T &theta, const T & phi)
{
    return Vec3<T>(cos(phi) * sin(theta),sin(phi) * sin(theta), cos(theta));
}

template<typename T>
T getTheta(const Vec3<T> v)
{
    return v.getTheta();
}

template<typename T>
T getPhi(const Vec3<T>v)
{
    return v.getPhi();
}


#endif