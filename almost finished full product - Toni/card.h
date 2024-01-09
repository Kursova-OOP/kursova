#ifndef UNTITLED11_CARD_H
#define UNTITLED11_CARD_H
#include <vector>
enum class Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum class Rank {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class Card {
public:
    Card(Suit suit, Rank rank);

    int getValue() const;
    void display() const;

private:
    Suit suit;
    Rank rank;
};

class Deck {
public:
    Deck();

    void shuffle();
    Card drawCard();
    int cardsLeft() const;
    void game();

private:
    std::vector<Card> cards;
};

void game();
#endif

