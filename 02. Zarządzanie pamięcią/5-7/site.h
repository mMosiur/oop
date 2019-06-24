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
    const std::string url;
    User users[100];
    int countUsers;
public:
    Site(const std::string &);
    Site(const Site &);
    std::string getUrl();
    bool addUser(const User);
    void printUsers();

    static int countCommon(const Site &, const Site &);
    static void writeCommon(const Site &, const Site &, std::string *);
};
#endif // SITE_H
