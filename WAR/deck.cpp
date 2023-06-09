#include "deck.h"
#include <algorithm>
#include <random>

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
