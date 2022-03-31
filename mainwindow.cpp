#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    this->holes[0] = ui->hole1;
    this->holes[1] = ui->hole2;
    this->holes[2] = ui->hole3;
    this->holes[3] = ui->hole4;
    this->holes[4] = ui->hole5;
    this->holes[5] = ui->hole6;

    update_holes();

    worker = QThread::create([this] { play(); });
    worker->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    worker->terminate();
    delete worker;
}

void MainWindow::play()
{
    while (true) {
        QThread::msleep(1000);
        digletts[0] = true;
        update_holes();
    }
}

void MainWindow::update_holes()
{
    for (int i = 0; i < 6; i++) {
        if (digletts[i])
            holes[i]->setPixmap(QPixmap(":/images/diglett.png"));
        else
            holes[i]->setPixmap(QPixmap(":/images/rock.png"));
    }
    ui->score->setText(QString::number(this->score));
    ui->health->setText(QString::number(this->health));
}

void MainWindow::hole_clicked(int index)
{
    if (digletts[index]) {
        score++;
        digletts[index] = false;
    }
    else {
        health--;
    }
    update_holes();
}

void MainWindow::on_hole1_clicked() { hole_clicked(0); }
void MainWindow::on_hole2_clicked() { hole_clicked(1); }
void MainWindow::on_hole3_clicked() { hole_clicked(2); }
void MainWindow::on_hole4_clicked() { hole_clicked(3); }
void MainWindow::on_hole5_clicked() { hole_clicked(4); }
void MainWindow::on_hole6_clicked() { hole_clicked(5); }
