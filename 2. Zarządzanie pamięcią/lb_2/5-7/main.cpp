#include <iostream>
#include "site.h"
#include <string>

using namespace std;
int main(){
    Site s1("https://kampus.umcs.pl/");
    puts("s1");
    cout<<s1.getUrl()<<endl;
    s1.addUser({"admin","123qwe"});
    s1.addUser({"ala", "123456"});
    s1.printUsers();
    string url="https://www.umcs.pl/";
    Site s2=url;
    puts("s2");
    cout<<s2.getUrl()<<endl;
    puts("s3");

    Site s3=s1;
    cout<<s3.getUrl()<<endl;
    s3.addUser({"Roman","kwiatuszek"});
    s3.printUsers();
    int size=Site::countCommon(s1,s3);
    cout<<"Size: "<<size<<endl;

    string *arr=new string[size];
    Site::writeCommon(s1,s3,arr);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    delete [] arr;
    return 0;
}
