#include <iostream>
#include <memory>

using namespace std;

struct Triangle {
    float a, b, c;
    Triangle(float a, float b, float c) : a{a}, b{b}, c{c}
    {}
};

float perimeterRef(shared_ptr<Triangle> & ptr) {
    cout << "X: " << ptr.use_count() << endl;
    return ptr->a + ptr->b + ptr->c;
}

float perimeterCopy(shared_ptr<Triangle> ptr) {
    cout << "Y: " << ptr.use_count() << endl;
    return ptr->a + ptr->b + ptr->c;
}

int main() {
    auto ptr = make_shared<Triangle>(3, 4, 5);
    cout << "C: " << ptr.use_count() << endl;
    perimeterRef(ptr);
    cout << "C: " << ptr.use_count() << endl;

    //cout << !ptr << endl;

    return 0;
}
