#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CMorse.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pBQuitter_clicked() {
    exit(0);
}

void MainWindow::on_pBClear_clicked() {
    ui->lEMessage->clear();
    ui->lEResultat->clear();
}

void MainWindow::on_pBCoder_clicked() {
    CMorse monMorse;
    char* msgTemp;
    msgTemp = new char[255];
    QString msg;
    msg = ui->lEMessage->text();
    strcpy(msgTemp, msg.toLatin1());
    monMorse.setMessageClair(msgTemp);
    if (monMorse.coderMorse() == true) {
        ui->lEResultat->setText(monMorse.getMessageCode());
    }
    else {
        ui->lEResultat->setText("");
    }
}
