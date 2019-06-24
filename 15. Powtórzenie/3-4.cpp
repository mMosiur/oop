#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>
using namespace std;

class StringList
{
    list<string> l;
    list<string>::iterator displayIterator;

public:
    StringList(list<string> l) :l(l){
        displayIterator = this->l.begin();
    }
    void operator()(string text, bool add){
        if(add)
            l.push_back(text);
        else{
            auto it=find(l.begin(), l.end(),text);
            if(it!=l.end())
                l.erase(it);
        }
    }
    void print(){
        for(string el:l)
            cout<<el<<endl;
    }
    friend ostream& operator<<(ostream& os, StringList& sl);
};

ostream& operator<<(ostream& os, StringList& sl){
    if(sl.displayIterator==sl.l.end()){
        sl.displayIterator=sl.l.begin();
        throw out_of_range("err");
    }
    os << *(sl.displayIterator);
    sl.displayIterator++;
    return os;
}
int main(int argc, char *argv[])
{
    list<string> l={"Ala", "ma","kota"};
    StringList obj(l);
    obj("Ala",1);
    for(int i=0; i<10; i++){
        try {
            cout << obj << " ";
        } catch (out_of_range &e) {
            cerr<<e.what()<<endl;
        }

    }
    return 0;
}
