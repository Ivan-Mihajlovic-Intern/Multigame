#include "flappybird.h"
#include "ui_flappybird.h"
#include <QGraphicsRectItem>
#include "player.h"
#include "obstacle.h"
#include "score.h"
#include "background.h"
#include <QGraphicsPixmapItem>
#include <QPalette>
#include <iostream>


FlappyBird::FlappyBird(int windowWidth, int windowHeight,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FlappyBird)
{
    ui->setupUi(this);
    m_timer = new QTimer();
    setResolution(windowWidth, windowHeight);
    setupScene();
    setupView();
    m_timer->start(1000/60);
}



FlappyBird::~FlappyBird()
{
    delete ui;
}

void FlappyBird::setupScene()
{
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0,0,getWindowWidth(),getWindowHeight());//member width and height

    //TODO:Fix background
    //setupBackground();
    setupPlayer();
    setupObstacles();
    setupScore();

}

void FlappyBird::setupView()
{
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(800,600);

}

void FlappyBird::setupPlayer()
{
    Player *player = new Player();
    player->setPos(player->playerOriginX(),player->playerOriginY());

    m_scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    connect(m_timer, SIGNAL(timeout()), player, SLOT(move()));

}

void FlappyBird::setupObstacles()
{
    newObstacle(300);
    newObstacle(550);
    newObstacle(800);
    newObstacle(1050);
}


void FlappyBird::setupScore()
{
    m_score = new Score();

    m_scene->addItem(m_score);
}

void FlappyBird::newObstacle(int posX)
{
    Obstacle *obstacleUp = new Obstacle();
    obstacleUp->setPos(posX,-100);
    obstacleUp->setTransformOriginPoint(25,160);
    obstacleUp->setRotation(180);

    connect(obstacleUp, &Obstacle::updateScore, this, &FlappyBird::onUpdateScore);
    connect(obstacleUp, &Obstacle::collisionOccurred, this, &FlappyBird::onCollisionOccurred);
    connect(m_timer, SIGNAL(timeout()), obstacleUp, SLOT(move()));

    Obstacle *obstacleDown = new Obstacle();
    obstacleDown->setPos(posX,400);
    connect(obstacleDown, &Obstacle::collisionOccurred, this, &FlappyBird::onCollisionOccurred);
    connect(m_timer, SIGNAL(timeout()), obstacleDown, SLOT(move()));

    m_scene->addItem(obstacleUp);
    m_scene->addItem(obstacleDown);
}

void FlappyBird::setupBackground()
{
    Background* background = new Background();
    m_scene->addItem(background);

    /*QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    m_scene->setPalette(palette);*/
}

void FlappyBird::onUpdateScore()
{
    m_score->increseScore();
}

void FlappyBird::onCollisionOccurred()
{
    m_timer->stop();
}
