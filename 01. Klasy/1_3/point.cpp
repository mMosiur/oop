#include "point.h"

Point::Point(float x, float y) {
    this->m_x=x;
    this->m_y=y;
}

float Point::y() const {
    return m_y;
}

float Point::x() const {
    return m_x;
}
