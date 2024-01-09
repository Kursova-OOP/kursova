#include "hangman.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Hangman::Hangman() {
    std::srand(std::time(nullptr)); // Seed the random number generator
    secretWord = getRandomWord();
    initializeWordStatus();
}


void Hangman::play() {

    int incorrectGuesses = 0;
    char guess;

    while (!isGameWon() && !isGameLost()) {
        displayWordStatus();
        displayIncorrectGuesses();
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        updateWordStatus(guess);

        if (secretWord.find(guess) == std::string::npos) {
            incorrectGuesses++;
        }

        displayHangman(incorrectGuesses);
    }

    if (isGameWon()) {
        std::cout << "Congratulations! You guessed the word: " << secretWord << std::endl;
    } else {
        std::cout << "Sorry, you lost! The word was: " << secretWord << std::endl;
    }
}

std::string Hangman::getRandomWord() {
    std::vector<std::string> words = { "apple", "banana", "cherry", "date", "elderberry" }; // Add more words as desired
    int randomIndex = std::rand() % words.size();
    return words[randomIndex];
}

void Hangman::initializeWordStatus() {
    wordStatus = std::string(secretWord.length(), '_');
}

void Hangman::displayWordStatus() {
    std::cout << "Word: " << wordStatus << std::endl;
}

void Hangman::updateWordStatus(char guess) {
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guess) {
            wordStatus[i] = guess;
        }
    }
}

bool Hangman::isGameWon() {
    return wordStatus == secretWord;
}

bool Hangman::isGameLost() {
    return incorrectGuesses.size() == 6; // Adjust the number of allowed incorrect guesses as desired
}

void Hangman::displayHangman(int incorrectGuesses) {
    // Display the hangman based on the number of incorrect guesses
    // Implement this method according to your desired representation of the hangman
    // You can use ASCII art or any other representation you prefer
}

void Hangman::displayIncorrectGuesses() {
    std::cout << "Incorrect guesses: ";
    for (char guess : incorrectGuesses) {
        std::cout << guess << " ";
    }
    std::cout << std::endl;
}
void Hangman::gaming() {
    Hangman game;
    game.play();
}
