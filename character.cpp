#include "character.h"

Character::Character(string Name, int Age, int Houses) {
    name = Name;
    age = Age;
    houses = Houses;
}

void Character::IntroduceYourself() {
    cout <<"Name - " << name << endl;
    cout <<"Age - " << age << endl;
    cout <<"Houses - " << houses << endl;
}


