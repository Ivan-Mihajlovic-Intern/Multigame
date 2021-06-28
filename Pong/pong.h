#ifndef PONG_H
#define PONG_H

#include <QDialog>
#include <QGraphicsScene>
#include "../src/game.h"

namespace Ui {
class Pong;
}

class Pong : public QDialog, public Game
{
    Q_OBJECT

public:
    explicit Pong(QWidget *parent = nullptr);
    ~Pong();

private:
    Ui::Pong *ui;

    QGraphicsScene* m_scene;
};

#endif // PONG_H
