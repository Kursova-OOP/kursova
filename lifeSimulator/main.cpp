#include <iostream>
#include "character.h"
using namespace std;


int main () {
    Character player1 = Character(" ", 0, 0,0);
    player1.enterData();
    player1.IntroduceYourself();
    player1.get_job();
    player1.family();
    player1.moneyManage();
    return 0;
}