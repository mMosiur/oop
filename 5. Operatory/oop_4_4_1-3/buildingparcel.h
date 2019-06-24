#ifndef BUILDINGPARCEL_H
#define BUILDINGPARCEL_H
#include "parcel.h"

class BuildingParcel : public Parcel
{
    struct House
    {
        unsigned int x,y,w,h;
    };
    House house;
    void drawRect(QImage &img);
public:
    BuildingParcel(Point* points, unsigned int size,unsigned int x,unsigned int y,unsigned int w,unsigned int h);
    void draw(const char *path);

};

#endif // BUILDINGPARCEL_H
