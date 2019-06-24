#include "site.h"
#include <iostream>


Site::Site(const std::string &url){
    this->url=url;
    countUsers=0;
}

Site::Site(const Site &s)
{
    this->url=s.url;
    this->countUsers=s.countUsers;
    for(int i=0;i<countUsers;i++){
        this->users[i].login=s.users[i].login;
    }
}

std::string Site::getUrl(){
    return url;
}

bool Site::addUser(const Site::User u)
{
    if(countUsers==100)
        return 0;
    for(int i=0;i<countUsers;i++)
        if(u.login==users[i].login)
            return 0;
    users[countUsers++]=u;
    return 1;
}

void Site::printUsers()
{
    for (int i=0;i<countUsers;i++) {
        std::cout<<"Login: "<<users[i].login<<"\nPassword: "<<users[i].password<<std::endl;
    }
}
