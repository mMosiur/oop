#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

int sum(int a, int b, int c) {
    return a+b-c;
}

bool notbetween(int min, int max, int i) {
    return !(i >= min && i < max);
}

int main(){
//    std::function<int(int,int)> f=std::bind(sum,10,std::placeholders::_2,std::placeholders::_1);
//    std::cout << f(20,100) << std::endl;

    std::function<bool(int)> f = std::bind(notbetween, 5, 20, std::placeholders::_1);
    std::vector<int> v = {1,2,6,4,8,21,45,54};
    std::replace_if(v.begin(), v.end(), f, 0);

    for(int i : v) {
        std::cout << i << std::endl;
    }

    return 0;
}
