#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

class Hangman {
public:
    Hangman();
    void play();
    void gaming();

private:
    std::string getRandomWord();
    void initializeWordStatus();
    void displayWordStatus();
    void updateWordStatus(char guess);
    bool isGameWon();
    bool isGameLost();
    void displayHangman(int incorrectGuesses);
    void displayIncorrectGuesses();

    std::string secretWord;
    std::string wordStatus;
    std::vector<char> incorrectGuesses;
};

#endif
