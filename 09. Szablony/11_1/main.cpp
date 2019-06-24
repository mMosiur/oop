#include <iostream>
#include <vector>
#include <algorithm>
#include "point.h"

using namespace std;

bool compareX(const Point &p, const Point &q) {
    return p.x() < q.x();
}

bool compareY(const Point &p, const Point &q) {
    return p.y() < q.y();
}

int main() {
    vector<Point> vec(3);

    vec[0]=Point(1,9);
    vec[1]=Point(5,8);
    vec[2]=Point(3,7);

    for(const Point &p : vec)
        cout << p.x() << " " << p.y() << endl;

    cout << endl;
    sort(vec.begin(),vec.end(),compareX);

    for(const Point &p : vec)
        cout << p.x() << " " << p.y() << endl;

    cout << endl;
    sort(vec.begin(),vec.end(),compareY);

    for(const Point &p : vec)
        cout << p.x() << " " << p.y() << endl;

    return 0;
}
