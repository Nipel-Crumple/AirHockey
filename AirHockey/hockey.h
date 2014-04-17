#ifndef HOCKEY_H
#define HOCKEY_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class Hockey;
}

class Hockey : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hockey(QWidget *parent = 0);
    ~Hockey();

private slots:
   // void exit_push();

private:
    Ui::Hockey *ui;
};



#endif // HOCKEY_H
