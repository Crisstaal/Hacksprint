/*#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/
#include <QApplication>
#include "riddlegame.h"

/** Main entry point of the program */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    RiddleGame game;
    game.setWindowTitle("Riddle Quiz Game");
    game.show();

    return app.exec();
}
