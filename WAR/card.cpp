#include "card.h"
#include <iostream>

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

int Card::getValue() const {
    // In this simple version, card value is equal to its rank
    return static_cast<int>(rank);
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
