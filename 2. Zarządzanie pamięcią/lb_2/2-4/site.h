#ifndef SITE_H
#define SITE_H
#include <string>


class Site
{
public:
    typedef struct {
        std::string login, password;
    }User;
private:
    std::string url;
    User users[100];
    int countUsers;
public:
    Site(const std::string &);
    Site(const Site &);
    std::string getUrl();
    bool addUser(const User);

    void printUsers();


};

#endif // SITE_H
