#include <iostream>
#include "Deck.h"

int main() {
    Deck deck;
    deck.shuffle();

    // Deal the cards to two players
    int cardsPerPlayer = deck.cardsLeft() / 2;

    std::cout << "WAR Card Game" << std::endl;

    for (int i = 0; i < cardsPerPlayer; i++) {
        Card player1Card = deck.drawCard();
        Card player2Card = deck.drawCard();

        std::cout << "Player 1: ";
        player1Card.display();
        std::cout << std::endl;

        std::cout << "Player 2: ";
        player2Card.display();
        std::cout << std::endl;

        if (player1Card.getValue() > player2Card.getValue()) {
            std::cout << "Player 1 wins the round!" << std::endl;
        } else if (player1Card.getValue() < player2Card.getValue()) {
            std::cout << "Player 2 wins the round!" << std::endl;
        } else {
            std::cout << "It's a tie!" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
