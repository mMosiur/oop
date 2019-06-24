#include <iostream>
#include <random>
#include <vector>
#include <memory>
#include <string>
#include <functional>
#include <exception>

using namespace std;

class WordBag{
    vector<unique_ptr<string>> vec;

    default_random_engine generator;
    function<int(void)> roll;

    void updateDistribution();
public:
    WordBag();
    void add(unique_ptr<string>);
    unique_ptr<string> take();
};
void WordBag::add(unique_ptr<string> str) {
    vec.push_back(move(str));
    updateDistribution();
}
unique_ptr<string>WordBag::take() {
    if(vec.empty())
        throw out_of_range("");
    int index = roll();
    unique_ptr<string> result(move(vec[index]));
    vec.erase(vec.begin()+index);
    updateDistribution();
    return result;
}
WordBag::WordBag() {
     random_device r;
     generator=default_random_engine(r());
}
void WordBag::updateDistribution() {
    uniform_int_distribution<int> distribution(0,vec.size()-1);
    roll = bind(distribution, generator);
}

int main() {
    WordBag wb;
    wb.add(make_unique<string>("ala"));
    wb.add(make_unique<string>("ma"));
    wb.add(make_unique<string>("kota"));
    cout << *wb.take() << endl;
    cout << *wb.take() << endl;
    cout << *wb.take() << endl;
    cout << *wb.take() << endl;


    return 0;
}
