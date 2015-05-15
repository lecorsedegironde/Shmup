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

    sf::Image m_playerImage;
    sf::Sprite m_playerSprite;

    sf::Image m_ennemyImage;
    sf::Sprite m_ennemySprite;

    sf::Image m_bossImage;
    sf::Sprite m_bossSprite;

    sf::Image m_explosionImage;
    sf::Sprite m_explosionSprite;

    sf::Image m_shotImage;
    sf::Sprite m_shotSprite;

    void initSprites();


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
