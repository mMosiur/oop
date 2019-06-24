#include "buildingparcel.h"
#include <QImage>
#include <QPainter>

void BuildingParcel::drawRect(QImage &img)
{
    QPainter painter(&img);
    painter.setBrush(QBrush(0xFF0000));
    painter.drawRect(house.x,house.y,house.w, house.h);
}

BuildingParcel::BuildingParcel(Point* points, unsigned int size,unsigned int x,unsigned int y,unsigned int w,unsigned int h)
    :Parcel(points,size)
{
    house.x=x;
    house.y=y;
    house.h=h;
    house.w=w;
}

void BuildingParcel::draw(const char *path)
{
    QPoint *qpoints= new QPoint[size];
    QImage img = prepareImage(qpoints);
    drawPolygon(img,qpoints,0x00FF00);
    drawRect(img);
    img.save(path);
    delete [] qpoints;
}
