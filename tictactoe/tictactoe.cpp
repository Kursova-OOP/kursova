#include "tictactoe.h"

TicTacToe::TicTacToe(QWidget* parent) : QWidget(parent) {
    // initialize buttons and layout
    layout = new QGridLayout(this);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j] = new QPushButton(this);
            buttons[i][j]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            buttons[i][j]->setText("");
            buttons[i][j]->setStyleSheet("font-size: 40px");
            layout->addWidget(buttons[i][j], i, j);
            connect(buttons[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));
        }
    }
    setLayout(layout);
}

void TicTacToe::buttonClicked() {
    QPushButton* button = (QPushButton*)sender();

    // mark the button with the current player's symbol
    if (button->text() == "") {
        if (currentPlayer == Player::X) {
            button->setText("X");
            currentPlayer = Player::O;
        }
        else {
            button->setText("O");
            currentPlayer = Player::X;
        }
        movesLeft--;
    }

    checkForWin();

    // check for a draw
    if (movesLeft == 0) {
        QMessageBox::information(this, "Game Over", "The game is a draw.");
        resetGame();
    }
}

void TicTacToe::checkForWin() {
    // check for horizontal wins
    for (int i = 0; i < 3; i++) {
        if (buttons[i][0]->text() != "" && buttons[i][0]->text() == buttons[i][1]->text() && buttons[i][1]->text() == buttons[i][2]->text()) {
            QMessageBox::information(this, "Game Over", buttons[i][0]->text() + " wins!");
            resetGame();
            return;
        }
    }

    // проверка за вертикални победи?
    for (int i = 0; i < 3; i++) {
        if (buttons[0][i]->text() != "" && buttons[0][i]->text() == buttons[1][i]->text() && buttons[1][i]->text() == buttons[2][i]->text()) {
            QMessageBox::information(this, "Game Over", buttons[0][i]->text() + " wins!");
            resetGame();
            return;
        }
    }

    // проверка за диагонални победи?
    if (buttons[0][0]->text() != "" && buttons[0][0]->text() == buttons[1][1]->text() && buttons[1][1]->text() == buttons[2][2]->text()) {
        QMessageBox::information(this, "Game Over", buttons[0][0]->text() + " wins!");
        resetGame();
        return;
    }
    if (buttons[0][2]->text() != "" && buttons[0][2]->text() == buttons[1][1]->text() && buttons[1][1]->text() == buttons[2][0]->text()) {
        QMessageBox::information(this, "Game Over", buttons[0][2]->text() + " wins!");
        resetGame();
        return;
    }
}

void TicTacToe::resetGame() {
    // reset the game state
    currentPlayer = Player::X;
    movesLeft = 9;

    // clear the button texts
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j]->setText("");
        }
    }
}

void TicTacToe::newGame() {
    // prompt the user to start a new game
    int reply = QMessageBox::question(this, "New Game", "Are you sure you want to start a new game?",
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        resetGame();
    }
}

void TicTacToe::quitGame() {
    // prompt the user to confirm quitting the game
    int reply = QMessageBox::question(this, "Quit Game", "Are you sure you want to quit the game?",
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qApp->quit();
    }
}

//#include "tictactoe.h"

TicTacToe::TicTacToe(QWidget* parent) : QWidget(parent) {
    //визия
    layout = new QGridLayout(this);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j] = new QPushButton(this);
            buttons[i][j]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            buttons[i][j]->setText("");
            buttons[i][j]->setStyleSheet("font-size: 40px");
            layout->addWidget(buttons[i][j], i, j);
            connect(buttons[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));
        }
    }
    setLayout(layout);

    /* add "New Game" and "Quit" buttons ???
    newGameButton = new QPushButton("New Game", this);
    quitButton = new QPushButton("Quit", this);
    layout->addWidget(newGameButton, 3, 0);
    layout->addWidget(quitButton, 3, 2);
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitGame()));
}
*/
