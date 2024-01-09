#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

class TicTacToe : public QWidget {
    Q_OBJECT

public:
    explicit TicTacToe(QWidget* parent = nullptr);

private slots:
    void buttonClicked();

private:
    enum class Player {
        None,
        X,
        O
    };

    Player currentPlayer = Player::X;

    QPushButton* buttons[3][3];
    QGridLayout* layout;
    int movesLeft = 9;

    void checkForWin();
    void resetGame();
};

#endif // TICTACTOE_H
