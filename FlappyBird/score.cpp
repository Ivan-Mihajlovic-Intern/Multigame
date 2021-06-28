#include "score.h"

#include <QFont>
#include <QString>


Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    m_score = 0;

    setPlainText(QString("Score:") + QString::number(m_score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("timers", 18));
}

void Score::increseScore()
{
    m_score++;
    setPlainText(QString("Score:") + QString::number(m_score));
}

int Score::getScore()
{
    return m_score;
}
