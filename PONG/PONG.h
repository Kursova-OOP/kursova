#ifndef PONG_H
#define PONG_H
// напомняне, че имам да сложа още една библоиотека
class Pong {
public:
    Pong();

    void run();

private:
    void processInput();
    void update();
    void render();

    bool gameOver;
    int paddle1Y;
    int paddle2Y;
    int ballX;
    int ballY;
    int ballSpeedX;
    int ballSpeedY;
    int paddle1Dir;
    int paddle2Dir;
};

#endif
