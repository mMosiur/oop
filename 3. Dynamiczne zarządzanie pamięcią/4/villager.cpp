#include "villager.h"

#include <cstdlib>
#include <ctime>

#include <iostream>

using namespace std;

string Villager::maleNames[10]={"Boguchwał", "Kazimierz", "Mieszko", "Świętosław", "Ziemowit"};
string Villager::femaleNames[10]={"Dobrowoja","Grzymisława", "Myślibora", "Radomiła", "Stronisława", "Zbysława"};
int Villager::maleNamesCount=5;
int Villager::femaleNamesCount=6;
bool Villager::randomized=false;

Villager::Villager(string name, int maxAge, int age, bool sex) {
    this->m_name=name; this->m_maxAge=maxAge;
    this->m_age=age; this->m_sex=sex;

    cout << name << " w wieku "  << age << " przybył" << (!m_sex ? "a" : "") << " do osady" << endl;
}

bool Villager::sex() const {
    return m_sex;
}

int Villager::age() const {
    return m_age;
}

Villager::Villager() {
    if(!randomized) {
        srand(time(0));
        randomized=true;
    }

    m_maxAge=rand()%100+1;
    m_age=0;
    m_sex=rand()%2;

    if(m_sex)
        m_name=maleNames[rand()%maleNamesCount];
    else
        m_name=femaleNames[rand()%femaleNamesCount];

    cout << m_name << " urodził" << (!m_sex ? "a" : "") << " się" << endl;
}

Villager::~Villager() {
    if(m_age==m_maxAge)
        cout << m_name << " umarł" << (!m_sex ? "a" : "") << endl;
    else
        cout << m_name << " opuscił" << (!m_sex ? "a" : "") << " osadę" << endl;
}

string Villager::ident() {
    string result;
    result+=m_name+" "+to_string(m_age);
    return result;
}

void Villager::advance() {
    m_age++;
}

bool Villager::readyToDie() {
    return m_age==m_maxAge;
}
