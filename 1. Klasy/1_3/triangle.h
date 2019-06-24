#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle {
    Point a, b, c;

    float distance(Point p, Point q);

public:
    Triangle(Point a, Point b, Point c);

    float perimeter();
    float area();
};

#endif // TRIANGLE_H
