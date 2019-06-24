#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include <string>

class Villager;

class Household
{
    int cap;
    Villager **inh;

public:
    Household(Villager *, int);
    ~Household();
    bool addVillager(Villager *);

    std::string ident();
    void advance();
    int currentCount();
    bool empty();
};

#endif // HOUSEHOLD_H
