//
// Created by HP on 20.5.2023 г..
//
#include "character.h"

Character::Character(string Name, int Age, int Money, int Expenses) {
    name = Name;
    age = Age;
    money = Money;
    expenses = Expenses;
}
void Character::enterData() {
    cout<<"Whats is your name?"<<endl;
    cin>>name;
    cout<<"What is your age?"<<endl;
    cin>>age;
    cout<<"How much money do you have in savings?"<<endl;
    cin>>money;
    cout<<"How much are your monthy expenses?"<<endl;
    cin>>expenses;
}

void Character::IntroduceYourself() {
    cout <<"Name - " << name << endl;
    cout <<"Age - " << age << endl;
    //cout <<"Houses - " << houses << endl;
    cout <<"Savings - " << money << endl;
    //cout <<"Income - " << income << endl;
    cout <<"Expenses - " << expenses << endl;
}
void Character::get_job() {
    cout<<"To choose a job, enter a number from 0 to 4";
    cin>>jobNumber;
    string jobs [5] = {"lawyer", "waiter/waitress", "accountant", "developer", "teacher", };
    int salaries[5] = {3500, 1800, 3000, 4500, 2500};
    cout<<"Now your job is "<<jobs[jobNumber]<<" and your monthly income is "<<salaries[jobNumber]<<"$ ."<<endl;
}
void Character::family() {
    cout<<"It's time to make an important choice...If you want to have a family (partner, two kids and a dog) enter 1. If you want to be solo enter 0"<<endl;
    cin>>choice;
    if (choice == 1) {
        cout<<"That's amazing, "<<name<<" ! You and your partner live happy life in a big house located in Delta Hill. You have two kids - boy and a girl and a husky dog"<<endl;
    }
    else if (choice == 0) {
        cout<<"You like living all by yourslef, "<<name<<" . You live in a luxorious apartment in Boyana. All your love and attention is for yoour family and friends"<<endl;
    }
}
void Character::moneyManage() {
    int choicefamily;
    int toInvest;

    if (choice == 1) {
        cout << "Now your expenses have increased to " << expenses + (expenses * 1.5)<< "$, and your saving have changed to " << money - (money * 0.5) << "$ ." << endl;
        cout<< "You can't cut your expenses much because you love your children and don't want to deprive them from anything. SO you have to increase your income."<< endl;
        cout<< "Enter 1 if you want to get your children to sell lemonade, or enter 0 if you want to rent a hall you have inherited from your grandparents"<< endl;
        cin>>choicefamily;
        if (choicefamily == 1) {
            cout <<"That was a wise choice. Now your children are growing as sensible people, who know how to manage their money. "<<endl;
            cout<<"Because they have been earning money by themselves, you and your partner did not have to give them money and your savings have increased."<<endl;
        } else if(choicefamily == 0) {
            cout<<"Now you and your partner are giving this hall for various events, you now have a passive income and your life is secured."<<endl;
        }
    }
    else if (choice == 0) {
        cout<<"By living all by yourself your expenses haven't changed much, but your savings are increasing each month. "<<endl;
        cout<<"You are very ambitious and you are thinking of investing your money in real estate."<<endl;
        cout<<"If you want to invest " << money-(money*0.25) <<"$ from your savign, enter 1, either enter 0"<<endl;
        cin>>toInvest;
        if (toInvest == 1) {
            cout<<"You made a good choice. Now you are secure for years. You have stable job, passive income and even give money to charity"<<endl;
        } else if (toInvest == 0) {
            cout<<"You have been alone for too long, and now you want to have a partner by your side."<<endl;
            cout<<"You fell in love with a person, but they are with you only for your money.Unfortunately, inflation devalued all your saving."<<endl;
            cout<<"You had to sell your apartment and move to your parents'. You remain only with the memories of your previous dream life"<<endl;
        }
    }
}

