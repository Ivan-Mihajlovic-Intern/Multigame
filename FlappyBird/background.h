#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Background: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Background();
};

#endif // BACKGROUND_H
