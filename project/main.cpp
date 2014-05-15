#include "gamewindow.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMessageBox* pmbx = new QMessageBox("GAME NAME",
                        "Start the game?",
                        QMessageBox::Information,
                        QMessageBox::Yes,
                        QMessageBox::No,
                        QMessageBox::Cancel);
    int n = pmbx->exec();
    delete pmbx;
    if (n == QMessageBox::Yes)
    {
        gameWindow w;
        w.resize(800, 480);
        w.show();
        return a.exec();
    }

    return 0;
}
