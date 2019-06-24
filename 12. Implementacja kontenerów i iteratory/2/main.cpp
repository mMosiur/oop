#include <iostream>
#include "list.h"

using namespace std;

int main(){
    List<int> l;
    l.push_front(5);
    l.push_front(10);
    l.push_front(15);
    l.push_front(20);

    for(int i : l)
        cout << i << endl;

//    cout << l.front() << endl;
//    cout << l.back() << endl;

    return 0;
}
