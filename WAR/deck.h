#ifndef UNTITLED11_DECK_H
#define UNTITLED11_DECK_H
#include <iostream>
#include "Card.h"
#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();

    void shuffle();
    Card drawCard();
    int cardsLeft() const;

private:
    std::vector<Card> cards;
};
#endif 
