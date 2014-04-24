#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMainWindow>

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
    QGraphicsEllipseItem *ball;
};

#endif // GAMEWINDOW_H
