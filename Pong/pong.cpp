#include "pong.h"
#include "ui_pong.h"

Pong::Pong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pong)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0,0,800,600);//member width and height

    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(800,600);
}

Pong::~Pong()
{
    delete ui;
}
