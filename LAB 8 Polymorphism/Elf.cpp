#include <string>
#include <iostream>

#include "Elf.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, string family) :
    Character(ELF, name, health, attackStrength), family(family) {}

void Elf::attack(Character &opponent) {
    if (opponent.getType() != ELF || (dynamic_cast<Elf&>(opponent)).family != this->family) {
        cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        opponent.damage((this->health / MAX_HEALTH) * this->attackStrength);
        cout << opponent.getName() << " takes " << (this->health / MAX_HEALTH) * this->attackStrength << " damage." << endl;
    } else {
        cout << "Elf " << this->name << " does not attack Elf " << opponent.getName() << "." << endl;
        cout << "They are both members of the " << this->family << " family." << endl;
    }
}
