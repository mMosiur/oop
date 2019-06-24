#include <iostream>
#include <list>
#include <string>

using namespace std;

void display(list<string>::iterator a, list<string>::iterator b) {
    for(auto it=a; it!=b; it++)
        cout << *it << "_";
}

int main() {
    list<string> l;
    l.push_back("Ala");
    l.push_back("ma");
    l.push_back("kota");
    l.push_front("zła");

    //*l.begin()="dobra";
    *(++++l.begin())="dobra";
    //l[2]="nie ma";

    //for(const string &s : l)
    //    cout << s << " ";

    display(l.begin(),l.end());

    return 0;
}
