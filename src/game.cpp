#include "game.h"

Game::Game()
{

}

int Game::getWindowWidth()
{
    return m_windowWidth;
}

int Game::getWindowHeight()
{
    return m_windowHeight;
}

QString Game::getGameName()
{
    return m_gameName;
}

void Game::setGameName(QString gameName)
{
    m_gameName = gameName;
}

void Game::setResolution(int windowWidth, int windowHeight)
{
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
}
