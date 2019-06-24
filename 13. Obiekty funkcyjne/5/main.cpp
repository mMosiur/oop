#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[]={4,2,6,8,6,2};
    int max=arr[0];
    for_each(arr+1, arr+6, [&max](int value){
       if(value>max)
           max=value;
    });

    cout << max << endl;
    return 0;
}
