#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QTimer>

#include "stick.h"

namespace Ui {
class gameWindow;
}

class gameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = 0);
    ~gameWindow();

private slots:
    void on_actionExit_triggered();

private:
    Ui::gameWindow *ui;
    QGraphicsScene *gameScene;
    stick *left_stick;
    stick *right_stick;
    QTimer *timer;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int flag_w;
    int flag_s;
    int flag_o;
    int flag_l;
    void key_event();
};

#endif // GAMEWINDOW_H
