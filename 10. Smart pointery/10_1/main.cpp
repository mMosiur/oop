#include <iostream>
using namespace std;
struct Point { float x, y; };
template <typename T>
class SmartPointer {
    T *raw;
public:
    SmartPointer(T *raw) {
        this->raw=raw;
    }
    ~SmartPointer() {
        delete raw;
    }
    T &operator *() {
        return *raw;
    }
    T *operator->() {
        return raw;
    }
};

int main() {
    SmartPointer<Point> ptr(new Point{2,3});
    cout << ptr->x << endl;
    return 0;
}
