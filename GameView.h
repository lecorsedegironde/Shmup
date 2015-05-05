#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameModel.h"

class GameView
{
private:
    int m_w;
    int m_h;
    int m_bpp;

    sf::RenderWindow * m_window;

    sf::Image m_backgroundImage;
    sf::Sprite m_backgroundSprite;

    GameModel * m_model;
public:
    static const int VIEW_W;
    static const int VIEW_H;
    static const int VIEW_BPP;

    GameView(int w, int h);
    GameView(int w, int h, int bpp);
    ~GameView();

    void setModel(GameModel * model);
    void draw();
    bool treatEvents();
};

#endif // GAMEVIEW_H
