#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include <QDialog>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "../src/game.h"

class Score;

namespace Ui {
class FlappyBird;
}

class FlappyBird : public QDialog, public Game
{
    Q_OBJECT

public:
    explicit FlappyBird(int windowWidth, int windowHeight,QWidget *parent = nullptr);
    ~FlappyBird();


private:
    Ui::FlappyBird *ui;

    QGraphicsScene *m_scene;
    Score *m_score;


    void setupScene();
    void setupView();
    void setupPlayer();

    /*This function is used to make obstacles and add them to the scene.
      It calls newObstacle() to make a new obstacle*/
    void setupObstacles();

    /*Instacniates m_score and adds it to scene*/
    void setupScore();

    /*Creates a new obstacle and sets its X coordinate to value provided by posX argument.
      Both top an bottom obastacle are created at once since they have the same X coordinate.
      After creating the obastacles eache of them is connected to certian signal. All obstacles
      are conneced to a game timer(defined inside FlappyBird class) and to collision detection.
      Only top obstacle is connected to score update.
      TODO: reiterate doc
      */
    void newObstacle(int posX);

    void setupBackground();
    QTimer* m_timer;

public slots:
    void onUpdateScore();
    void onCollisionOccurred();
};

#endif // FLAPPYBIRD_H
