#include <iostream>
#include <memory>

using namespace std;

struct Triangle {
    float a, b, c;
    Triangle(float a, float b, float c) : a{a}, b{b}, c{c}
    {}
};

float perimeterRef(unique_ptr<Triangle> & ptr) {
    return ptr->a + ptr->b + ptr->c;
}

float perimeterCopy(unique_ptr<Triangle> ptr) {
    return ptr->a + ptr->b + ptr->c;
}

int main() {
    unique_ptr<Triangle> ptr = make_unique<Triangle>(3, 4, 5);
    cout << perimeterRef(ptr) << endl;
    //cout << !ptr << endl;

    return 0;
}
