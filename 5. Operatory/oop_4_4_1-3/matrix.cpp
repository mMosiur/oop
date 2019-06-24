#include "matrix.h"

Vec3f operator +(const Vec3f &v1, const Vec3f &v2)
{
    return {v1.x+v2.x,v1.y+v2.y,v1.z+v2.z};
}

Vec3f &operator +=(Vec3f &a, const Vec3f &b)
{
    a.x+=b.x;
    a.y+=b.y;
    a.z+=b.z;
    return a;
}

Vec3f Vec3f::operator *(const Vec3f &b) const
{
    return {y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x};
}
Vec3f& Vec3f::operator *=(const Vec3f &b)
{
    Vec3f temp;
    temp.x = y*b.z - z*b.y;
    temp.y = z*b.x - x*b.z;
    temp.z = x*b.y - y*b.x;
    *this = temp;
    return *this;
}
Vec3f Vec3f::operator *(const float &b) const
{
    return {x * b, y * b, z * b};
}

Vec3f& Vec3f::operator *=(const float &b)
{
    x *= b;
    y *= b;
    z *= b;
    return *this;
}

Mat3x3f Mat3x3f:: operator*(const Mat3x3f &b) const
{
    Mat3x3f result={0};
   for(int i=0; i<3; i++)
       for(int j=0; j<3; j++)
           for(int k=0; k<3; k++)
               result.arr[i*3 + j] += this->arr[i*3 +k] * b.arr[k*3 +j];

    return result;
}

Mat3x3f& Mat3x3f::operator *=(const Mat3x3f& b)
{
    *this = *this * b;
    return *this;

}

Vec3f& operator *=(Vec3f& a, const Mat3x3f& b){
    Vec3f result;
    result.x = a.x * b.arr[0] + a.y * b.arr[1] + a.z * b.arr[2];
    result.y = a.x * b.arr[3] + a.y * b.arr[4] + a.z * b.arr[5];
    result.z = a.x * b.arr[6] + a.y * b.arr[7] + a.z * b.arr[8];
    a=result;
    return a;
}

Vec3f operator*(Vec3f& a, const Mat3x3f& b){
    Vec3f result;
    result.x = a.x * b.arr[0] + a.y * b.arr[1] + a.z * b.arr[2];
    result.y = a.x * b.arr[3] + a.y * b.arr[4] + a.z * b.arr[5];
    result.z = a.x * b.arr[6] + a.y * b.arr[7] + a.z * b.arr[8];
    return result;
}


