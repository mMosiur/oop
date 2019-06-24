#ifndef MATRIX_H
#define MATRIX_H

struct Vec3f {
    float x,y,z;

    Vec3f operator *(const Vec3f &b) const;
    Vec3f& operator *=(const Vec3f &b);
    Vec3f operator *(const float &b) const;
    Vec3f& operator *=(const float &b);

};

struct Mat3x3f;

Vec3f operator +(const Vec3f &v1,const Vec3f &v2);
Vec3f& operator +=(Vec3f& a, const Vec3f& b);

Vec3f& operator *=(Vec3f& a, const Mat3x3f& b);
Vec3f operator*(Vec3f& a, const Mat3x3f& b);

struct Mat3x3f {
    float arr[9];
    Mat3x3f operator*(const Mat3x3f &b) const;
    Mat3x3f& operator *=(const Mat3x3f& b);
};






#endif // MATRIX_H
