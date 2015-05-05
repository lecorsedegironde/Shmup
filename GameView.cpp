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
    m_window = new RenderWindow(sf::VideoMode(w, h, bpp), "Shmup", sf::Style::Close);

    m_window->SetFramerateLimit(30);

    if (!m_backgroundImage.LoadFromFile("images/revive.png"))
    {
        m_backgroundSprite = Sprite ();
    }
    else
    {
        m_backgroundSprite = Sprite (m_backgroundImage);
        m_backgroundSprite.Resize(m_w, m_h);
        m_backgroundSprite.SetPosition(0,0);
    }
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
    m_window->Clear();
    m_window->Draw(m_backgroundSprite);
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

            }
            else if ((event.Type == Event::KeyPressed) && (event.Key.Code == sf::Key::S))
            {

            }
        }
    }

    return retour;
}
