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

    //Chargement des sprites
    initRessources();
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
    //On clear l'écran et on dessine le fond
    m_window->Clear();
    m_window->Draw(m_backgroundSprite);

    //On récupère les positions
    int xJoueur, yJoueur;
    m_model->getJoueurPos(xJoueur, yJoueur);
    m_playerSprite.SetPosition(xJoueur, yJoueur);

    //On récupère les tirs
    for(auto it : m_model->getTir())
    {
        TirAllie *t = dynamic_cast<TirAllie*>(it);
        if (t != nullptr)
        {
            m_shotSprite.SetSubRect(IntRect(0, 12, 55, 22));
        }
        else
        {
            m_shotSprite.SetSubRect(IntRect(0, 0, 55, 10));
        }

        int xTir = it->getX();
        int yTir =  it->getY();
        m_shotSprite.SetPosition(xTir, yTir);
        m_window->Draw(m_shotSprite);
    }

    //On récupère les ennemis
    for (auto it : m_model->getEnnemi())
    {

        m_ennemySprite.SetSubRect(IntRect(0, 0, 120, 79));
        m_ennemySprite.SetPosition(it->getX(), it->getY());
        m_window->Draw(m_ennemySprite);
    }

    //On dessine

    m_window->Draw(m_playerSprite);
    m_window->Display();
}

bool GameView::treatEvents()
{
    //TODO Déplacements plus élégants
    bool retour = false;

    if(m_window->IsOpened())
    {
        retour = true;
        Event event;
        const Input& input = m_window->GetInput();

        while (m_window->GetEvent(event))
        {
            if (event.Type == Event::Closed)
            {
                m_window->Close();
                retour = false;
            }
        }

        int dxJoueur = 0;
        int dyJoueur = 0;

        if (input.IsKeyDown(Key::Escape))
        {
            m_window->Close();
            retour = false;
        }
        if (input.IsKeyDown(Key::Z))
        {
            dyJoueur = -Joueur::JOUEUR_X_SPEED;
        }
        if (input.IsKeyDown(Key::S))
        {
            dyJoueur = Joueur::JOUEUR_X_SPEED;
        }
        if (input.IsKeyDown(Key::Q))
        {
            dxJoueur = -Joueur::JOUEUR_Y_SPEED;
        }
        if (input.IsKeyDown(Key::D))
        {
            dxJoueur = Joueur::JOUEUR_Y_SPEED;
        }
        if (input.IsKeyDown(Key::Space))
        {
            m_model->tirPlayer();

        }

        m_model->setJoueurSpeed(dxJoueur, dyJoueur);
    }

    return retour;
}

void GameView::initRessources()
{
    //On créée des sprites vides en cas de crash

    //Le fond
    if(!m_backgroundImage.LoadFromFile("images/planet.png"))
    {
        m_backgroundSprite = Sprite ();
    }
    else
    {
        m_backgroundSprite = Sprite(m_backgroundImage);
        m_backgroundSprite.Resize(m_w, m_h);
        m_backgroundSprite.SetPosition(0,0);
    }

    //Les boutons
    if(!m_buttonImage.LoadFromFile("images/buttons.png"))
    {
        m_buttonSprite = Sprite();
    }
    else
    {
        m_buttonSprite = Sprite(m_buttonImage);
    }

    //Les ennemis
    if(!m_ennemyImage.LoadFromFile("images/ennemy.png"))
    {
        m_ennemySprite = Sprite();
    }
    else
    {
        m_ennemySprite = Sprite(m_ennemyImage);
    }

    //Le boss
    if(!m_bossImage.LoadFromFile("images/boss.png"))
    {
        m_bossSprite = Sprite();
    }
    else
    {
        m_bossSprite = Sprite(m_bossImage);
    }

    //Les explosions
    if(!m_explosionImage.LoadFromFile("images/explosion.png"))
    {
        m_explosionSprite = Sprite();
    }
    else
    {
        m_explosionSprite = Sprite(m_explosionImage);
    }

    //Le joueur
    if(!m_playerImage.LoadFromFile("images/player.png"))
    {
        m_playerSprite = Sprite();
    }
    else
    {
        m_playerSprite = Sprite(m_playerImage);
    }

    //Les tirs
    if(!m_shotImage.LoadFromFile("images/shot.png"))
    {
        m_shotSprite = Sprite();
    }
    else
    {
        m_shotSprite = Sprite(m_shotImage);
    }

    //La police du menu
    if(!m_font1.LoadFromFile("polices/kenvector_future.ttf"))
    {
        m_font1 = Font::GetDefaultFont();
    }
}

//Le Menu
void GameView::drawMenu()
{
    //Pour savoir si les boutons sont survolés pas la souris
    const Input& input = m_window->GetInput();
    bool isPlaySelected, isQuitSelected;
    if (input.GetMouseX() > 100 && input.GetMouseX() < 290 && input.GetMouseY() > 400 && input.GetMouseY() < 450)
    {
        isPlaySelected = true;
        isQuitSelected = false;
    }
    else if (input.GetMouseX() > 510 && input.GetMouseX() < 700 && input.GetMouseY() > 400 && input.GetMouseY() < 450)
    {
        isPlaySelected = false;
        isQuitSelected = true;
    }
    else
    {
        isPlaySelected = false;
        isQuitSelected = false;
    }

    //On clear l'écran et on dessine le fond
    m_window->Clear();
    m_window->Draw(m_backgroundSprite);

    //On récupère la taille du bouton
    Vector2f buttonSize = m_buttonSprite.GetSize();

    //Bouton play
    //Ici, on dessine le bouton
    Vector2f buttonPos(100, 400);
    if (!isPlaySelected)
    {
        m_buttonSprite.SetSubRect(IntRect(0, 0, 190, 50));
    }
    else
    {
        m_buttonSprite.SetSubRect(IntRect(192, 0, 382, 45));
    }
    m_buttonSprite.SetPosition(buttonPos);
    m_window->Draw(m_buttonSprite);

    //Et ici, le texte du bouton
    String play("Play", m_font1, 30);
    Vector2f playPos(buttonPos.x + (buttonSize.x/2 - 45), 402);
    play.SetPosition(playPos);
    m_window->Draw(play);

    //Bouton quit
    if (!isQuitSelected)
    {
        m_buttonSprite.SetSubRect(IntRect(0, 0, 190, 50));
    }
    else
    {
        m_buttonSprite.SetSubRect(IntRect(192, 0, 382, 45));
    }
    buttonPos.x = GameView::VIEW_W - (100 + buttonSize.x);
    buttonPos.y = 400;
    m_buttonSprite.SetPosition(buttonPos);
    m_window->Draw(m_buttonSprite);

    String quit("Quit", m_font1, 30);
    Vector2f quitPos(buttonPos.x + (buttonSize.x/2 - 35), 402);
    quit.SetPosition(quitPos);
    m_window->Draw(quit);

    //Titre
    String titre("SHMUP", m_font1, 50);
    titre.SetPosition(300, 150);
    m_window->Draw(titre);

    m_window->Display();
}

bool GameView::treatMenuEvents()
{
    bool retour = false;

    if(m_window->IsOpened())
    {
        retour = true;

        Event event;
        const Input& input = m_window->GetInput();

        while (m_window->GetEvent(event))
        {
            if (event.Type == Event::Closed)
            {
                m_window->Close();
                retour = false;
            }
        }


        if (input.IsMouseButtonDown(Mouse::Left) &&
                (input.GetMouseX() > 100 && input.GetMouseX() < 290
                 && input.GetMouseY() > 400 && input.GetMouseY() < 450))
        {
            retour = false;
        }
        else if (input.IsKeyDown(Key::Escape) || (input.IsMouseButtonDown(Mouse::Left) &&
                 (input.GetMouseX() > 510 && input.GetMouseX() < 700
                  && input.GetMouseY() > 400 && input.GetMouseY() < 450)))
        {
            m_window->Close();
            retour = false;
        }
    }

    return retour;
}
