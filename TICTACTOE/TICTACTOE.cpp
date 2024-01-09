#include "TICTACTOE.h"
#include <iostream>

TicTacToe::TicTacToe() {
    initializeBoard();
    currentPlayer = 'X'; // 'X' започва играта
}

void TicTacToe::play() {
    int row, col;

    while (!isGameWon(currentPlayer) && !isBoardFull()) {
        displayBoard();

        std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
        std::cin >> row >> col;

        if (isMoveValid(row, col)) {
            makeMove(row, col, currentPlayer);
            switchPlayer();
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    displayBoard();

    if (isGameWon(currentPlayer)) {
        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }
}

void TicTacToe::initializeBoard() {
    board = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
}

void TicTacToe::displayBoard() {
    std::cout << "   1   2   3" << std::endl;
    std::cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "  ---+---+---" << std::endl;
    std::cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "  ---+---+---" << std::endl;
    std::cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

bool TicTacToe::isMoveValid(int row, int col) {
    // проверка дали кллетката на дъската е заета
    return row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ';
}

bool TicTacToe::makeMove(int row, int col, char player) {
    // слагане на знакът, поставен от играча на дтъската
    if (isMoveValid(row, col)) {
        board[row - 1][col - 1] = player;
        return true;
    }
    return false;
}

bool TicTacToe::isGameWon(char player) {
    // проверка за победа по редове
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // проверка за победа по колони
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // проверка за победа по диагонали
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool TicTacToe::isBoardFull() {
    // проверка за край на играта, ако цялата дъска е пълна, играта приклюва
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

void TicTacToe::switchPlayer() {
    // смяна на играчите
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
