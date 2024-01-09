#ifndef HANGMAN_H
#define HANGMAN_H

#include <QString>

class Hangman {
public:
    Hangman();

    void startGame();
    void guessLetter(const QChar& letter);
    bool isGameOver() const;
    bool isGameWon() const;
    QString getWordToGuess() const;
    QString getGuessedWord() const;
    QString getGuessedLetters() const;
    int getNumWrongGuesses() const;

private:
    QString wordToGuess;
    QString guessedWord;
    QString guessedLetters;
    int numWrongGuesses;
};

#endif // HANGMAN_H