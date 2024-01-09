#include <iostream>
#include <conio.h>
#include "PONG.h"

const int WIDTH = 60;
const int HEIGHT = 20;

Pong::Pong() {
    gameOver = false;
    paddle1Y = HEIGHT / 2 - 2;
    paddle2Y = HEIGHT / 2 - 2;
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    ballSpeedX = -1;
    ballSpeedY = 0;
    paddle1Dir = 0;
    paddle2Dir = 0;
}

void Pong::run() {
    while (!gameOver) {
        processInput();
        update();
        render();
    }
}

void Pong::processInput() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'w' || key == 'W')
            paddle1Dir = -1;
        if (key == 's' || key == 'S')
            paddle1Dir = 1;
        if (key == 'i' || key == 'I')
            paddle2Dir = -1;
        if (key == 'k' || key == 'K')
            paddle2Dir = 1;
        if (key == 'q' || key == 'Q')
            gameOver = true;
    }
}

void Pong::update() {
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    // горна и долна сстена
    if (ballY <= 0 || ballY >= HEIGHT - 1)
        ballSpeedY = -ballSpeedY;

    // движения на топчрто спрямо правоъгълниичето
    if ((ballX == 1 && paddle1Y <= ballY && ballY < paddle1Y + 4) ||
        (ballX == WIDTH - 2 && paddle2Y <= ballY && ballY < paddle2Y + 4))
        ballSpeedX = -ballSpeedX;
    
    // движение на правоъгълничто
    paddle1Y += paddle1Dir;
    paddle2Y += paddle2Dir;
}

void Pong::render() {
    system("cls");

    //горна стебна
    for (int i = 0; i < WIDTH + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    // топка и правоъгълниеч
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 || x == WIDTH - 1)
                std::cout << "#";
            else if (x == ballX && y == ballY)
                std::cout << "O";
            else if (x == 1 && (y == paddle1Y || y == paddle1Y + 1 || y == paddle1Y + 2 || y == paddle1Y + 3))
                std::cout << "|";
            else if (x == WIDTH - 2 && (y == paddle2Y || y == paddle2Y + 1 || y == paddle2Y + 2 || y == paddle2Y + 3))
                std::cout << "|";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    // долна стена
    for (int i = 0; i < WIDTH + 2; i++)
        std::cout << "#";
    std::cout << std::endl;
}
