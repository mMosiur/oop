#include <iostream>
#include <cmath>

using namespace std;

class Point {
    float m_x,m_y;

    public:
    Point(float x, float y);
    float x() const;
    float y() const;
    void move(Point p);
};

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

void Point::move(Point p) {
    m_x += p.m_x;
    m_y += p.y();
}

float distance(Point p, Point q) {
    float dx=p.x()-q.x();
    float dy=p.y()-q.y();
    return sqrt(dx*dx+dy*dy);
}

int main() {
    Point a(1,2), b(3,4);
    a.move(b);
    cout << a.x() << " " << a.y() << endl;
    cout << distance(a,b) <<endl;
    return 0;
}

