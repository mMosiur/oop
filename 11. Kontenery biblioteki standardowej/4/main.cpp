#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> sum(const vector<int> &a, const vector<int> &b) {
    set<int> s;
//    for(int i : a)
//        s.insert(i);

//    for(int i : b)
//        s.insert(i);

//    vector<int> result;
//    for(int i : s)
//        result.push_back(i);

    s.insert(a.begin(),a.end());
    s.insert(b.begin(),b.end());
    return vector<int>(s.begin(),s.end());
}

int main() {
    vector<int> a(3), b(4);
    {
        int arr[3]={1,5,8};
        copy_n(arr,3,a.begin());
    }
    {
        int arr[4]={1,8,3,1};
        copy_n(arr,4,b.begin());
    }

    vector<int> result=sum(a,b);

    for(int i : result)
        cout << i << " ";

    return 0;
}
