#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

class TicTacToe {
public:
    TicTacToe();
    void play();

private:
    void initializeBoard();
    void displayBoard();
    bool isMoveValid(int row, int col);
    bool makeMove(int row, int col, char player);
    bool isGameWon(char player);
    bool isBoardFull();
    void switchPlayer();

    std::vector<std::vector<char>> board;
    char currentPlayer;
};

#endif
