#include <iostream>
#include <list>

using namespace std;


template < template<typename ...> class C, typename T>
T &minOfContainer(C<T> container) {
    T &min=*container.begin();
    for(T &current : container) {
        if(current < min)
            min=current;
    }
    return min;
}


int main() {
    list<int> l;
    l.push_back(10);
    l.push_back(5);
    l.push_back(15);

    cout << minOfContainer(l) << endl;

    return 0;
}
