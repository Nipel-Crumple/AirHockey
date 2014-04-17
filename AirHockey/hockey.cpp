#include "hockey.h"
#include "my_ui.h"
#include <QLabel>
#include <QLayout>
#include <QPixmap>
#include <QVBoxLayout>

Hockey::Hockey(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hockey)
{
    ui->setupUi(this);                                                          //installing visual options in MainWindow
    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));         //adding button "exit"

}

Hockey::~Hockey()
{
    delete ui;
}
