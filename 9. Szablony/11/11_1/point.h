#ifndef POINT_H
#define POINT_H

class Point
{
    float m_x, m_y;
public:
    Point();
    Point(float x, float y);

    float x() const;
    void setX(float x);
    float y() const;
    void setY(float y);
};

#endif // POINT_H
