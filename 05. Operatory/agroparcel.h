#ifndef AGROPARCEL_H
#define AGROPARCEL_H
#include "parcel.h"


class AgroParcel : public Parcel
{
private:
    static int colors[3];

public:
   enum CultureType {Tomato, Cucumber, Potato};
    AgroParcel(Point* points, unsigned int size, CultureType culturetype);
    ~AgroParcel();
     void draw(const char* path);

private:
      CultureType culturetype;

};

#endif // AGROPARCEL_H
