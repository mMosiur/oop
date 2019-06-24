#include "agroparcel.h"


int main() {

    Point points[4] = {{100,0},{500,100},{300,700},{0,300}};
    Parcel *p =new AgroParcel(points,4,AgroParcel::Cucumber);

    p->draw("/Users/student/oop2019/img.png");
    delete p;
    return 0;
}
