#include <iostream>
#include "triangle.h"

using namespace std;

int main() {
    Triangle t(Point(13,23), Point(12,3), Point(32,41));
    cout << t.perimeter() << " " << t.area() << endl;
    return 0;
}
