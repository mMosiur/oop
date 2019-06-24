#include <iostream>
#include <thread>
#include <chrono>

#include "villager.h"
#include "household.h"

using namespace std;

int main() {
    Villager *husband=new Villager("Wacek",85,5,true);
    Villager *wife=new Villager();

    Household *house=new Household(husband,6);
    while(!house->addVillager(wife)) {
        delete wife;
        wife=new Villager();
    }


    while(!house->empty()) {
        house->advance();
        cout << house->ident() << "\n";
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "I nie było już nikogo" << endl;

    return 0;
}
