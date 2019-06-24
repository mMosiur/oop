//zadanie 5
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countDigit(int value, int digit) {
    string vs = to_string(value);
    return count(vs.begin(),vs.end(),digit+'0');
}

// a)

class Sorter {
    int digit;
public:
    Sorter(int digit) : digit(digit) {}
    bool operator()(const int &a, const int &b) {
        return countDigit(a,digit) < countDigit(b,digit);
    }
};

void sortByDigitUsingFunctor(vector<int>::iterator begin, vector<int>::iterator end, int digit) {
    if(digit<0 || digit/10 != 0)
        throw digit;
    Sorter sorter(digit);
    sort(begin,end,sorter);
}

// b)
#include <functional>

bool compareByDigit(const int &a, const int &b, const int &digit) {
    return countDigit(a,digit) < countDigit(b,digit);
}

void sortByDigitUsingBind(vector<int>::iterator begin, vector<int>::iterator end, int digit) {
    if(digit<0 || digit/10 != 0)
        throw digit;
    function<bool(const int &, const int &)> compare=bind(compareByDigit, placeholders::_1, placeholders::_2, digit);
    sort(begin,end,compare);
}

// c)
void sortByDigitUsingLambda(vector<int>::iterator begin, vector<int>::iterator end, int digit) {
    if(digit<0 || digit/10 != 0)
        throw digit;
    sort(begin,end,[digit](const int &a, const int &b) {
        return countDigit(a,digit) < countDigit(b,digit);
    });
}

int main() {
    vector<int> v = {45222, 75, 22, 71, 23045, 1002, 5224};
    try {
        //sortByDigitUsingFunctor(v.begin(),v.end(),2);
        //sortByDigitUsingBind(v.begin(),v.end(),2);
        sortByDigitUsingLambda(v.begin(),v.end(),-2);
    }
    catch(int e) {
        cerr << e << endl;
    }

    for(int i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
