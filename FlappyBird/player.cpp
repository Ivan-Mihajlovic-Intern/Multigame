#include "player.h"


Player::Player()
{
    setPixmap(QPixmap(":/flappybird/FlappyBird/images/yellowbird-midflap.png"));

    /*m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));

    m_timer->start(1000/60);*/
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        setPos(x(), y()-30);
    }
}

int Player::playerOriginX()
{
    return m_playerOriginX;
}

int Player::playerOriginY()
{
    return m_playerOriginY;
}

void Player::move()
{
   setPos(x(), y()+2);
}
