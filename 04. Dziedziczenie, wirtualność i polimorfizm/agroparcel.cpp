#include "agroparcel.h"
#include <QImage>
#include <QPainter>
#include <iostream>
int AgroParcel::colors[3] = {0xAA3939, 0x479030, 0xAAA839};

AgroParcel::AgroParcel(Point* points, unsigned int size, CultureType culturetype)
    :Parcel(points, size), culturetype(culturetype)
{

}

AgroParcel::~AgroParcel()
{
    std::cout << "agroparcel\n";
}

void AgroParcel::draw(const char* path)
{
    commonDraw(path,colors[culturetype]);
}
