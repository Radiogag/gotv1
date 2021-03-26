#include "game.h"

#include <QApplication>

#include "QDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game g(6);

    return a.exec();
}
