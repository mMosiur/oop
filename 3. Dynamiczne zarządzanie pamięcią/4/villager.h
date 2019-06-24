#ifndef VILLAGER_H
#define VILLAGER_H

#include <string>

class Villager {

    static std::string maleNames[10];
    static std::string femaleNames[10];
    static bool randomized;

    static int maleNamesCount, femaleNamesCount;

    std::string m_name;
    int m_maxAge;
    int m_age;
    bool m_sex;
public:
    Villager();
    Villager(std::string name ,int maxAge, int max, bool sex);
    ~Villager();
    std::string ident();
    void advance();
    bool readyToDie();
    bool sex() const;
    int age() const;
};

#endif // VILLAGER_H
