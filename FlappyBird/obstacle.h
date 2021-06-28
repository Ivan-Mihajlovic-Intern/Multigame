#ifndef OBSACLE_H
#define OBSACLE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Obstacle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Obstacle();

signals:
    void updateScore();
    void collisionOccurred();
public slots:
    void move();
};

#endif // OBSACLE_H
