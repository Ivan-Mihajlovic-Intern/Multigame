#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();

    void keyPressEvent(QKeyEvent *event);
    int playerOriginX();
    int playerOriginY();

private:

    int m_playerOriginX = 100;
    int m_playerOriginY = 320;

public slots:
    void move();

};

#endif // PLAYER_H
