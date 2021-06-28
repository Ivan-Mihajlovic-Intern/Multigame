#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "../FlappyBird/flappybird.h"
#include "../Pong/pong.h"
#include "../Demolition/demolition.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->pbFlappyBird->setStyleSheet("border-image:url(:/images/images/flappybird.jpg);");
    ui->pbDemolition->setStyleSheet("border-image:url(:/images/images/demolition.png);");
    ui->pbPong->setStyleSheet("border-image:url(:/images/images/pong.jpg);");

    connect(ui->pbHighScore, &QPushButton::clicked, this, &MainWindow::onClickedHighScore);
    connect(ui->pbFlappyBird, &QPushButton::clicked, this, &MainWindow::onClickedFlappyBird);
    connect(ui->pbDemolition, &QPushButton::clicked, this, &MainWindow::onClickedDemolition);
    connect(ui->pbPong, &QPushButton::clicked, this, &MainWindow::onClickedPong);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClickedHighScore()
{

}

void MainWindow::onClickedFlappyBird()
{
    FlappyBird game(800,600);
    game.resize(800, 600);
    game.setModal(true);
    game.exec();

}

void MainWindow::onClickedDemolition()
{
    Demolition game;
    game.setResolution(800,600);
    game.resize(800, 600);
    game.setModal(true);
    game.exec();
}

void MainWindow::onClickedPong()
{
    Pong game;
    game.setResolution(800,600);
    game.resize(800, 600);
    game.setModal(true);
    game.exec();

}

