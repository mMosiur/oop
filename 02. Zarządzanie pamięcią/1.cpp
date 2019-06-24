//zadanie 1

#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    cout<<s<<endl;
    char first='z', last ='a';
    char d='a'-'A', c;
    for (size_t i=0;i<s.length();i++) {
        c=s[i];
        if(c>='A' && c<='Z') c+=d;
        if (c>='a' && c<='z'){
            if(c<first)first=c;
            if(c>last) last=c;
        }
    }
    cout << "First: "<<first<<"\nLast: "<<last << endl;
    return 0;
}
