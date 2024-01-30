#include <string>
#include <iostream>

#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) :
    Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {}

void Warrior::attack(Character &opponent) {
    // check if opponent should be attacked
    if (opponent.getType() != WARRIOR || (dynamic_cast<Warrior&>(opponent)).allegiance != this->allegiance) {
        cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        opponent.damage((this->health / MAX_HEALTH) * this->attackStrength);
        cout << opponent.getName() << " takes " << (this->health / MAX_HEALTH) * this->attackStrength << " damage." << endl;
    } else {
        cout << "Warrior " << this->name << " does not attack Warrior " << opponent.getName() << "." << endl;
        cout << "They share an allegiance with " << this->allegiance << "." << endl;
    }
}
