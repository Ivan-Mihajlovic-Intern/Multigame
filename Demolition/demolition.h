#ifndef DEMOLITION_H
#define DEMOLITION_H

#include <QDialog>
#include <QGraphicsScene>
#include "../src/game.h"

namespace Ui {
class Demolition;
}

class Demolition : public QDialog, public Game
{
    Q_OBJECT

public:
    explicit Demolition(QWidget *parent = nullptr);
    ~Demolition();

private:
    Ui::Demolition *ui;

    QGraphicsScene *m_scene;
};

#endif // DEMOLITION_H
