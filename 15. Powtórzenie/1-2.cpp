//zadanie 1 
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
map<T, int> count(list<T> arg){
    map<T, int> result;
    for(auto it=arg.begin();it!=arg.end();it++){
        auto it2=result.find(*it);
        if(it2==result.end())
            result.insert(pair<T, int> (*it,1));
        else {
            it2->second++;
        }
    }

    return result;
}

//zadanie 2
template <>
map<string, int> count(list<string> arg){
    map<string, int> result;
    for(auto it=arg.begin();it!=arg.end();it++){
        stringstream ss(*it);
        string word;
        while(ss>>word){
            auto it2=result.find(word);
            if(it2==result.end())
                result.insert(pair<string, int> (word,1));
            else {
                it2->second++;
            }
        }
    }

    return result;
}

int main()
{
    /*list<char> l={'a','b','c','a','a','e', 'r','c'};
    map<char, int> r=count<char>(l);
    */
    list<string> l={"Ala ma kota","Tola ma kota","Koty to zlo"};
    map<string, int> r=count<string>(l);

    for(auto elem : r)
        cout << elem.first << " " << elem.second << "\n";

    return 0;
}
