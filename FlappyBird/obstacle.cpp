#include "obstacle.h"
#include "player.h"

Obstacle::Obstacle()
{
    setPixmap(QPixmap(":/flappybird/FlappyBird/images/pipe-green.png"));

    /*m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));

    m_timer->start(1000/60);*/
}

void Obstacle::move()
{
    QList<QGraphicsItem *> listOfCollidingItems = collidingItems();

    for(size_t i=0; i < listOfCollidingItems.size(); i++)
    {
        if(typeid(*(listOfCollidingItems[i])) == typeid(Player))
            emit collisionOccurred();
    }

    //check for reset
    //add a default start position so reset can be performed on that position


    if(x() < -100)
        setPos(900, y());

    if(x() < 50 && x()>46)
        emit updateScore();
    setPos(x()-3, y());
}
