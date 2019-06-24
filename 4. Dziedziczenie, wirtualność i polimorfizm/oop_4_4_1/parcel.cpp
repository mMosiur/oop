#include "parcel.h"
#include <QImage>
#include <QPainter>
#include <iostream>

Parcel::Parcel(Point* points, unsigned int size)
{
    this->points = new Point [size];
    memcpy(this->points,points,sizeof(Point)*size);
    this->size = size;
}

Parcel::~Parcel()
{
    std::cout << "parcel\n";
    delete [] points;
}

void Parcel::draw(const char* path) {
    commonDraw(path,0xFFFFFF);
}

void Parcel::commonDraw(const char* path, unsigned int color){
    int max_y,max_x;
    max_x = 0;
    max_y = 0;
    QPoint* qpoints = new QPoint [size];

    for(int i = 0; i < size; i++) {
        if(max_x < points[i].x)
            max_x = points[i].x;

        if(max_y < points[i].y)
            max_y = points[i].y;

        qpoints[i] = QPoint(points[i].x,points[i].y);

    }

    QImage img(max_x,max_y,QImage::Format_RGB32);

    QPainter painter(&img);
    img.fill(0xFFFFFF);
    painter.setBrush(QBrush(color));
    painter.drawPolygon(qpoints,size);
    img.save(path);
    delete [] qpoints;
}
