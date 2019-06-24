#include "household.h"
#include "villager.h"
#include <iostream>

using namespace std;

Household::Household(Villager *owner, int cap) {
    inh=new Villager*[cap];
    for(int i=0; i<cap; i++)
        inh[i]=nullptr;

    inh[0]=owner;
    this->cap=cap;
}

Household::~Household() {
    delete [] inh;
}

string Household::ident() {
    string result;
    for(int i=0; i<cap; i++)
        if(inh[i]!=nullptr)
            result+=inh[i]->ident()+"\n";
    return result;
}

bool Household::addVillager(Villager *v){
    int room=-1;
    for(int i=0; i<cap; i++) {
        if(inh[i]==nullptr) {
            room=i;
        }
        else {
            if(inh[i]->sex()==v->sex())
                return false;
        }
    }
    if(room!=-1) {
        inh[room]=v;
        return true;
    }
    else
        return false;
}

void Household::advance() {
    bool female=false, male=false, child=false;

    for(int i=0; i<cap; i++)
        if(inh[i]!=nullptr) {
            inh[i]->advance();

            if(inh[i]->readyToDie()) {
                delete inh[i];
                inh[i]=nullptr;
                continue;
            }

            if(inh[i]->age()>=18 && inh[i]->age()<=40 && inh[i]->sex()==true)
                female=true;
            if(inh[i]->age()>=18 && inh[i]->age()<=40 && inh[i]->sex()==false)
                male=true;
            if(inh[i]->age()<=5)
                child=true;
        }
    if(female && male && !child) {
        for(int i=0; i<cap; i++)
            if(inh[i]==nullptr) {
                inh[i]=new Villager();
                break;
            }
    }

}

int Household::currentCount() {
    int sum=0;
    for(int i=0; i<cap; i++)
        if(inh[i]!=nullptr)
            sum++;
    return sum;
}

bool Household::empty() {
    for(int i=0; i<cap; i++)
        if(inh[i])
            return false;
    return true;
}
