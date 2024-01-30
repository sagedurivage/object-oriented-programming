#include <string>

#include "Character.h"

using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength) {
    this->type = type;
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
}

HeroType Character::getType() const {
    return type;
}

const string & Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return static_cast <int> (health);
}

void Character::damage(double d) {
    health -= d;
}

bool Character::isAlive() const {
    return health > 0;
}
