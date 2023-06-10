#include "card.h"
#include <iostream>
#include <algorithm>
#include <random>


Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

int Card::getValue() const {
    // In this simple version, card value is equal to its rank
    return static_cast<int>(rank);
}

Deck::Deck() {
    // Initialize the deck with all 52 cards
    for (int suit = static_cast<int>(Suit::CLUBS); suit <= static_cast<int>(Suit::SPADES); suit++) {
        for (int rank = static_cast<int>(Rank::ACE); rank <= static_cast<int>(Rank::KING); rank++) {
            cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 rng(rd());

    std::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::drawCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}

int Deck::cardsLeft() const {
    return static_cast<int>(cards.size());
}

void Card::display() const {
    std::string suitString;
    std::string rankString;

    switch (suit) {
        case Suit::CLUBS:
            suitString = "Clubs";
            break;
        case Suit::DIAMONDS:
            suitString = "Diamonds";
            break;
        case Suit::HEARTS:
            suitString = "Hearts";
            break;
        case Suit::SPADES:
            suitString = "Spades";
            break;
    }

    switch (rank) {
        case Rank::ACE:
            rankString = "Ace";
            break;
        case Rank::JACK:
            rankString = "Jack";
            break;
        case Rank::QUEEN:
            rankString = "Queen";
            break;
        case Rank::KING:
            rankString = "King";
            break;
        default:
            rankString = std::to_string(static_cast<int>(rank));
    }

    std::cout << rankString << " of " << suitString;
}

void Deck::game(){

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
}

