#include <iostream>
#include "array.h"
#include <utility>

using namespace std;

int main() {
    Array<pair<int, float>> arr(3);
    arr[0]=make_pair(1,2);
    arr[1]=make_pair(3,4);
    arr[2]=make_pair(5,6);


//    for(int i=0; i<arr.size(); i++)
//        cout << arr[i] << endl;

//    for(double d : arr)
//        cout << d << endl;

//    Array<double>::iterator it;


    for(auto it=arr.begin(); it!=arr.end(); it++)
        cout << it->first << endl;

    return 0;
}
