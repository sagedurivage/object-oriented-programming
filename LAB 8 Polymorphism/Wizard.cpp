#include <string>
#include <iostream>

#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) :
    Character(WIZARD, name, health, attackStrength), rank(rank) {}

void Wizard::attack(Character &opponent) {
    if (opponent.getType() != WIZARD) {
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        opponent.damage(this->attackStrength);
        cout << opponent.getName() << " takes " << this->attackStrength << " damage." << endl;
    } else {
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        opponent.damage(((this->rank * 1.0) / ((dynamic_cast<Wizard&>(opponent)).rank)) * this->attackStrength);
        cout << opponent.getName() << " takes "
             << ((this->rank * 1.0) / ((dynamic_cast<Wizard&>(opponent)).rank)) * this->attackStrength << " damage." << endl;
    }
}
