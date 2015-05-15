#include <iostream>
#include <cstdlib>
#include "GameView.h"

using namespace std;
using namespace sf;

const int GameView::VIEW_W = 800;
const int GameView::VIEW_H = 600;
const int GameView::VIEW_BPP = 32;

GameView::GameView(int w, int h)
    : GameView(w, h, GameView::VIEW_BPP)
{}

GameView::GameView(int w, int h, int bpp)
    : m_w {w}, m_h {h}, m_bpp {bpp}
{
    m_window = new RenderWindow(VideoMode(w, h, bpp), "Shmup", Style::Close);

    m_window->SetFramerateLimit(30);

    //CHargement des sprites
    initSprites();


}

GameView::~GameView()
{
    if (m_window != nullptr)
        delete m_window;
}


void GameView::setModel(GameModel * model)
{
    m_model = model;
}

void GameView::draw()
{
    //On récupére les positions
    int xJoueur, yJoueur;
    //int wJoueur, hJoueur;
    m_model->getJoueurPos(xJoueur, yJoueur);
    //m_model->getJoueurSize(wJoueur, hJoueur);
    m_playerSprite.SetPosition(xJoueur, yJoueur);
    //m_playerSprite.Resize(wJoueur, hJoueur);

    //On dessine
    m_window->Clear();
    m_window->Draw(m_backgroundSprite);
    m_window->Draw(m_playerSprite);


    m_window->Display();
}

bool GameView::treatEvents()
{
    //TODO Déplacements
    bool retour = false;

    if(m_window->IsOpened())
    {
        retour = true;
        Event event;
        while (m_window->GetEvent(event))
        {
            if ((event.Type == Event::Closed) ||
                    ((event.Type == Event::KeyPressed) && (event.Key.Code == sf::Key::Escape)))
            {
                m_window->Close();
                retour = false;
            }
            else if ((event.Type == Event::KeyPressed) && (event.Key.Code == sf::Key::Z))
            {
                int xJoueur, yJoueur;
                m_model->getJoueurPos(xJoueur, yJoueur);
                m_model->setJoueurPos(xJoueur, yJoueur-5);
            }
            else if ((event.Type == Event::KeyPressed) && (event.Key.Code == sf::Key::S))
            {
                int xJoueur, yJoueur;
                m_model->getJoueurPos(xJoueur, yJoueur);
                m_model->setJoueurPos(xJoueur, yJoueur+5);
            }
            else if ((event.Type == Event::KeyPressed) && (event.Key.Code == sf::Key::Q))
            {
                int xJoueur, yJoueur;
                m_model->getJoueurPos(xJoueur, yJoueur);
                m_model->setJoueurPos(xJoueur-5, yJoueur);
            }
            else if ((event.Type == Event::KeyPressed) && (event.Key.Code == sf::Key::D))
            {
                int xJoueur, yJoueur;
                m_model->getJoueurPos(xJoueur, yJoueur);
                m_model->setJoueurPos(xJoueur+5, yJoueur);
            }
        }
    }

    return retour;
}

//TODO Add the use of different sprites style
void GameView::initSprites()
{
    //On créée des sprites vides au cas ou ça plante
    m_backgroundSprite = Sprite ();
    m_buttonSprite = Sprite();
    m_ennemySprite = Sprite();
    m_bossSprite = Sprite();
    m_explosionSprite = Sprite();
    m_playerSprite = Sprite();
    m_shotSprite = Sprite();

    if(m_backgroundImage.LoadFromFile("images/planet.png"))
    {
        m_backgroundSprite = Sprite(m_backgroundImage);
        m_backgroundSprite.Resize(m_w, m_h);
        m_backgroundSprite.SetPosition(0,0);
    }

    if(m_buttonImage.LoadFromFile("images/buttons.png"))
    {
        m_buttonSprite = Sprite(m_buttonImage);
    }

    if(m_ennemyImage.LoadFromFile("images/ennemy.png"))
    {
        m_ennemySprite = Sprite(m_ennemyImage);
    }

    if(m_bossImage.LoadFromFile("images/boss.png"))
    {
        m_bossSprite = Sprite(m_bossImage);
    }

    if(m_explosionImage.LoadFromFile("images/explosion.png"))
    {
        m_explosionSprite = Sprite(m_explosionImage);
    }

    if(m_playerImage.LoadFromFile("images/player.png"))
    {
        m_playerSprite = Sprite(m_playerImage);
    }

    if(m_shotImage.LoadFromFile("images/shot.png"))
    {
        m_shotSprite = Sprite(m_shotSprite);
    }








}
