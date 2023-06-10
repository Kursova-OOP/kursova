//
// Created by HP on 20.5.2023 г..
//

#ifndef LIFESIMULATOR2_CHARACTER_H
#define LIFESIMULATOR2_CHARACTER_H
#include <iostream>
using namespace std;

class Character {
public:
    Character(string Name, int Age, int Money, int Expenses);

    void enterData();
    void IntroduceYourself();
    void get_job();
    void family();
    void moneyManage();
    void play();
private:
    int choice{};
    int jobNumber{};
    string name;
    int money;
    int income{};
    int expenses;
    int age;
};



#endif //LIFESIMULATOR2_CHARACTER_H
