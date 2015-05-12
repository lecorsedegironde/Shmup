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

    //TODO Add all sprites

    sf::RenderWindow * m_window;

    sf::Image m_backgroundImage;
    sf::Sprite m_backgroundSprite;

    sf::Image m_buttonImage;
    sf::Sprite m_buttonSprite;

    sf::Image m_soldierImage;
    sf::Sprite m_soldierSprite;

    sf::Image m_scoutImage;
    sf::Sprite m_scoutSprite;

    sf::Image m_tankImage;
    sf::Sprite m_tankSprite;

    sf::Image m_sniperImage;
    sf::Sprite m_sniperSprite;

    sf::Image m_bossImage;
    sf::Sprite m_bossSprite;

    sf::Image m_explosionImage;
    sf::Sprite m_explosionSprite;

    sf::Image m_shotImage;
    sf::Sprite m_shotSprite;



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
