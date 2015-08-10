#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setTracking(false);
    bool res=ledControl.OpenPort();
    if(!res)
    {
        QMessageBox box;
        box.setText("Can not open port");
        box.exec();
        QApplication::quit();
    }

    //writting to the port instantly fails for some reason. Wait a second.
    QTime dieTime= QTime::currentTime().addSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    //sync gui and arduino value for start up.
    on_horizontalSlider_valueChanged(ui->horizontalSlider->value());

    //off to start;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug()<<"Sending "<<value<<". "<<"Sent ok? "<<ledControl.write(255-(char)value);
}
