#include <QApplication>
#include "hangman.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    HangmanGame game;
    game.show();

    return app.exec();
}
