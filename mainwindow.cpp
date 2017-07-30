#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{

}

QString MainWindow::get_name_file() {
    return QFileDialog::getOpenFileName(0,QObject::tr("хуй"), QDir::currentPath(), QObject::tr("[eq"));
}
