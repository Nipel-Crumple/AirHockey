#include "hockey.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hockey w;
    w.show();

    return a.exec();
}
