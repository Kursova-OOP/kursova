#include <iostream>
#include "character.h"
using namespace std;


Character::Character(string Name, int Age, int Money, int Expenses) {
    name = Name;
    age = Age;
    money = Money;
    expenses = Expenses;
}

void Character::enterData() {
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "What is your age?" << endl;
    cin >> age;
    cout << "How much money do you have in savings?" << endl;
    cin >> money;
    cout << "How much are your monthly expenses?" << endl;
    cin >> expenses;
}

void Character::IntroduceYourself() {
    cout << "Name - " << name << endl;
    cout << "Age - " << age << endl;
    cout << "Savings - " << money << endl;
    cout << "Expenses - " << expenses << endl;
}

void Character::get_job() {
    cout << "To choose a job, enter a number from 0 to 4: ";
    cin >> jobNumber;
    string jobs[5] = {"lawyer", "waiter/waitress", "accountant", "developer", "teacher"};
    int salaries[5] = {3500, 1800, 3000, 4500, 2500};
    cout << "Now your job is " << jobs[jobNumber] << " and your monthly income is $" << salaries[jobNumber] << "." << endl;
}

void Character::family() {
    cout << "It's time to make an important choice..." << endl;
    cout << "If you want to have a family (partner, two kids, and a dog), enter 1." << endl;
    cout << "If you want to be solo, enter 0." << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "That's amazing, " << name << "! You and your partner live a happy life in a big house located in Delta Hill." << endl;
        cout << "You have two kids - a boy and a girl - and a husky dog." << endl;
    } else if (choice == 0) {
        cout << "You like living all by yourself, " << name << "." << endl;
        cout << "You live in a luxurious apartment in Boyana." << endl;
        cout << "All your love and attention is for your family and friends." << endl;
    }
}

void Character::moneyManage() {
    int choicefamily;
    int toInvest;

    if (choice == 1) {
        cout << "Now your expenses have increased to " << expenses + (expenses * 1.5) << "$, and your savings have changed to " << money - (money * 0.5) << "$." << endl;
        cout << "You can't cut your expenses much because you love your children and don't want to deprive them of anything." << endl;
        cout << "So you have to increase your income." << endl;
        cout << "Enter 1 if you want to get your children to sell lemonade, or enter 0 if you want to rent a hall you have inherited from your grandparents: ";
        cin >> choicefamily;

        if (choicefamily == 1) {
            cout << "That was a wise choice. Now your children are growing as sensible people who know how to manage their money." << endl;
            cout << "Because they have been earning money by themselves, you and your partner did not have to give them money, and your savings have increased." << endl;
        } else if (choicefamily == 0) {
            cout << "Now you and your partner are giving this hall for various events." << endl;
            cout << "You now have a passive income, and your life is secured." << endl;
        }
    } else if (choice == 0) {
        cout << "By living all by yourself, your expenses haven't changed much, but your savings are increasing each month." << endl;
        cout << "You are very ambitious and you are thinking of investing your money in real estate." << endl;
        cout << "If you want to invest " << money - (money * 0.25) << "$ from your savings, enter 1. Otherwise, enter 0: ";
        cin >> toInvest;

        if (toInvest == 1) {
            cout << "You made a good choice. Now you are secure for years." << endl;
            cout << "You have a stable job, passive income, and even give money to charity." << endl;
        } else if (toInvest == 0) {
            cout << "You have been alone for too long, and now you want to have a partner by your side." << endl;
            cout << "You fell in love with a person, but they are with you only for your money." << endl;
            cout << "Unfortunately, inflation devalued all your savings." << endl;
            cout << "You had to sell your apartment and move to your parents'." << endl;
            cout << "You remain only with the memories of your previous dream life." << endl;
        }
    }
}

void Character::play() {
    Character player1("John", 0, 0,0);
    player1.enterData();
    player1.IntroduceYourself();
    player1.get_job();
    player1.family();
    player1.moneyManage();
}

