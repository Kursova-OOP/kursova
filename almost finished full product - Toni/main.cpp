#include <iostream>
#include <cstdlib> // For system("clear") or system("cls")
#include "tictactoe.h"
#include "RockPaperScissors.h"
#include "hangman.h"
#include "card.h"
#include "character.h"

// Function to clear the console screen
void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

// Function to display the menu options
void displayMenu() {
    std::cout << "Welcome to the Game Menu!" << std::endl;
    std::cout << "Please choose a game to open:" << std::endl;
    std::cout << "1. Tic Tac Toe" << std::endl;
    std::cout << "2. Hangman" << std::endl;
    std::cout << "3. Rock Paper Scissors" << std::endl;
    std::cout << "4. Life Simulator" << std::endl;
    std::cout << "5. War" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

int main() {
    int choice;
    bool exitMenu = false;

    while (!exitMenu) {
        clearScreen();
        displayMenu();

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                clearScreen();
                TicTacToe ticTacToe;
                ticTacToe.play();
                break;
            }
            case 2: {
                clearScreen();
                Hangman hangman;
                hangman.gaming();
                break;
            }
            case 3: {
                clearScreen();
                RockPaperScissors game;
                game.run();
                break;
            }
            case 4: {
                clearScreen();
                Character game("John", 20, 15000,5000); // nqma da igraem s tezi parametri, NO SA NUJNI ZA DA RUNVA PROGRAMATA(NE SE PIPA!!!)
                game.play();
                break;
            }
            case 5: {
                clearScreen();
                Deck play;
                play.game();
                break;
            }
            case 6:
                exitMenu = true;
                break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }

                if (!exitMenu) {
                    std::cout << "\nPress Enter to continue...";
                    std::cin.ignore();
                    std::cin.get();
                }
        }

        std::cout << "Exiting the Game Menu. Goodbye!" << std::endl;
        return 0;
    }
