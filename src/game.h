#ifndef GAME_H
#define GAME_H

#include <QString>

class Game
{
public:
    Game();

    int getWindowWidth();
    int getWindowHeight();
    QString getGameName();

    void setGameName(QString gameName);
    void setResolution(int windowWidth, int windowHeight);

private:
    int m_windowWidth;
    int m_windowHeight;
    QString m_gameName;

};

#endif // GAME_H
