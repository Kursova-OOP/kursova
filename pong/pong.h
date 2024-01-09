#ifndef PONG_H
#define PONG_H

#include <QWidget>
#include <QLabel>

class Pong : public QWidget {
    Q_OBJECT

public:
    Pong(QWidget* parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* event);
    void update();

private:
    QLabel* leftPaddle;
    QLabel* rightPaddle;
    QLabel* ball;
    int dx;
    int dy;
    int leftScore;
    int rightScore;
    QLabel leftScoreLabel;
    QLabel rightScoreLabel;
};

#endif // PONG_H
