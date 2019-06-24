#include "agroparcel.h"
#include "buildingparcel.h"
#include <string>
#include <iostream>
#include "matrix.h"

using namespace std;

int main() {
    Mat3x3f m1={1,2,3,0,1,0,0,0,1};
    Mat3x3f m2={2,0,0,0,1,0,0,0,1};
    Mat3x3f m3=m1*m2;

    for(int i=0; i<9; i++)
        cout << m3.arr[i] << " ";
//    Vec3f v1={1,2,3};
//    Vec3f v2={2,0,0};
//    Vec3f v3 = v1 * v2;
//    cout << v3.x << " " << v3.y << " " << v3.z << "\n";
    return 0;
}

/*
    Point points[4] = {{100,0},{500,100},{300,700},{0,300}};
    //Parcel *p =new BuildingParcel(points,4,100,400,200,100);

    Parcel *p[3];
    p[0] = new BuildingParcel(points,4,100,400,200,100);
    p[1] = new AgroParcel(points,4,AgroParcel::Tomato);
    p[2] = new Parcel(points,4);

    string path;
    AgroParcel *ap;
    for(int i=0; i<3; i++) {
        ap = dynamic_cast<AgroParcel *>(p[i]);
        if(ap) {
            path = string("/Users/student/oop2019/img_") + to_string(i) +
                    string(".png");
            ap->draw(path.c_str());
        }
        delete p[i];
    }

    return 0;
}
*/
