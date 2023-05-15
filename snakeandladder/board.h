#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    int getNextPosition(int currentPosition, int diceRoll);
private:
    int boardSize;
    int numSnakes;
    int numLadders;
    int* snakes;
    int* ladders;
};

#endif // BOARD_H
