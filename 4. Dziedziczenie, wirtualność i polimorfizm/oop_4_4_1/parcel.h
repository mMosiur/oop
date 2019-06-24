#ifndef PARCEL_H
#define PARCEL_H

class QPainter;

struct Point
{
    unsigned int x,y;
};

class Parcel
{
protected:
    Point* points;
    unsigned int size;

    void commonDraw(const char* path, unsigned int color);

public:
    Parcel(Point* points, unsigned int size);
    virtual ~Parcel();
    virtual void draw(const char* path);
};

#endif // PARCEL_H
