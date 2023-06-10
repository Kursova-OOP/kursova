#ifndef UNTITLED13_ROCK_PAPER_SCISSORS_H
#define UNTITLED13_ROCK_PAPER_SCISSORS_H

class RockPaperScissors {
public:
    void run();

private:
    char getUserChoice();
    char getComputerChoice();
    void showChoice(char choice);
    void chooseWinner(char player, char computer);
};

#endif //UNTITLED13_ROCK_PAPER_SCISSORS_H
