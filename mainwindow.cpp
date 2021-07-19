#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "eventCrashes.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_nativeCrashButton_clicked()
{
    qDebug() << "NativeCrashButton Pressed";
    startup();
}


void MainWindow::on_sentryCrashButton_clicked()
{
    qDebug() << "sentryCrashButton Pressed";
    send_event();
}

