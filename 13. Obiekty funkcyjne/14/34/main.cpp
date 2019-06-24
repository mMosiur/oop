#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    float x, y;
};

// bool f(int a, int b) { return a<b; }

int main() {
    vector<Point> v={
        Point{7,5},
        Point{2,3},
        Point{1,2}
    };
    Point center{10,10};

    function<bool(Point a, Point b)> f=[&center](Point a, Point b) {
        return hypot(a.x-center.x, a.y-center.y) < hypot(b.x-center.x, b.y-center.y);
    };

    sort(v.begin(),v.end(),f);

    for(Point p : v) {
        cout << p.x << " " << p.y << endl;
    }

    center=Point{0,0};

    sort(v.begin(),v.end(),f);


    cout << endl;

    for(Point p : v) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}
