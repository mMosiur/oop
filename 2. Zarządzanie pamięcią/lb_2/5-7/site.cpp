#include "site.h"
#include <iostream>
Site::Site(const std::string &url):url(url), countUsers(0){
}

Site::Site(const Site &s):url(s.url),countUsers(s.countUsers){
    for(int i=0;i<countUsers;i++){
        this->users[i].login=s.users[i].login;
    }
}

std::string Site::getUrl(){
    return url;
}

bool Site::addUser(const Site::User u){
    if(countUsers==100)
        return 0;
    for(int i=0;i<countUsers;i++)
        if(u.login==users[i].login)
            return 0;
    users[countUsers++]=u;
    return 1;
}

void Site::printUsers(){
    for (int i=0;i<countUsers;i++) {
        std::cout<<"Login: "<<users[i].login<<"\nPassword: "<<users[i].password<<std::endl;
    }
}

int Site::countCommon(const Site &s1, const Site &s2){
    int count=0;
    for(int i=0;i<s1.countUsers;i++){
        for(int j=0;j<s2.countUsers;j++){
            if(s1.users[i].login==s2.users[j].login)
                count++;
        }
    }
    return count;
}

void Site::writeCommon(const Site &s1, const Site &s2, std::string *common){
    int k=0;
    for(int i=0;i<s1.countUsers;i++)
        for(int j=0;j<s2.countUsers;j++)
            if(s1.users[i].login==s2.users[j].login)
                common[k++]=s1.users[i].login;
}
