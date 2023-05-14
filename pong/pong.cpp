#include "pong.h"
#include <QMessageBox>
#include <QHBoxLayout>
#include <QKeyEvent>

Pong::Pong(QWidget* parent) : QWidget(parent), dx(5), dy(5), leftScore(0), rightScore(0) {
    // правоъгълничета (такива, в които да се удря топката)
    leftPaddle = new QLabel(this);
    leftPaddle->setGeometry(0, 120, 10, 60);
    leftPaddle->setStyleSheet("background-color: white;");

    rightPaddle = new QLabel(this);
    rightPaddle->setGeometry(380, 120, 10, 60);
    rightPaddle->setStyleSheet("background-color: white;");

    // топче
    ball = new QLabel(this);
    ball->setGeometry(190, 140, 20, 20);
    ball->setStyleSheet("background-color: white;");

    // изписване на резултат
    leftScoreLabel.setText("0");
    rightScoreLabel.setText("0");

    // как да изглежда програмата
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(&leftScoreLabel);
    layout->addStretch();
    layout->addWidget(leftPaddle);
    layout->addWidget(ball);
    layout->addWidget(rightPaddle);
    layout->addStretch();
    layout->addWidget(&rightScoreLabel);

    // записване на времето в таймер
    startTimer(20);
}

void Pong::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_W:
        leftPaddle->move(leftPaddle->x(), leftPaddle->y() - 10);
        break;
    case Qt::Key_S:
        leftPaddle->move(leftPaddle->x(), leftPaddle->y() + 10);
        break;
    case Qt::Key_Up:
        rightPaddle->move(rightPaddle->x(), rightPaddle->y() - 10);
        break;
    case Qt::Key_Down:
        rightPaddle->move(rightPaddle->x(), rightPaddle->y() + 10);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void Pong::update() {
    // движение на топката
    ball->move(ball->x() + dx, ball->y() + dy);

    // проверка за нацелен удар
    if (ball->y() <= 0 || ball->y() + ball->height() >= height()) {
        dy = -dy;
    }

        //проверка за пропуснат удар
    if (ball->x() <= leftPaddle->x() + leftPaddle->width() && ball->y() + ball->height() >= leftPaddle->y() && ball->y() <= leftPaddle->y() + leftPaddle->height()) {
        dx = -dx;
    }

    if (ball->x() + ball->width() >= rightPaddle->x() && ball->y() + ball->height() >= rightPaddle->y() && ball->y() <= rightPaddle->y() + rightPaddle->height()) {
        dx = -dx;
    }

    // резултат
    if (ball->x() <= 0) {
        rightScore++;
        rightScoreLabel.setText(QString::number(rightScore));
        ball->move(190, 140);
        dx = -dx;
    }

    if (ball->x() + ball->width() >= width()) {
        leftScore++;
        leftScoreLabel.setText(QString::number(leftScore));
        ball->move(190, 140);
        dx = -dx;
    }
}

void Pong::timerEvent(QTimerEvent*) {
    update();
}


