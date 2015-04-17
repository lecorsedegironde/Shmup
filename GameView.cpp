#include <iostream>
#include <cstdlib>
#include "GameView.h"

using namespace std;

const int GameView::VIEW_W = 800;
const int GameView::VIEW_H = 600;
const int GameView::VIEW_BPP = 32;

GameView::GameView(int w, int h)
    : m_w {w}, m_h {h}
{}

GameView::~GameView()
{}


void GameView::setModel(GameModel * model)
{
    m_model = model;
}

void GameView::draw()
{
    cout << m_model->toString() << endl;
}

bool GameView::treatEvents()
{
    bool retour = true;
    string event;

    cin >> event;

    if (event == "quit" || event == "exit")
    {
        retour = false;
    }
    else if (event == "haut" || event == "z")
    {
        m_model->movePlayer(0, Joueur::JOUEUR_Y_SPEED);
    }
    else if (event == "bas" || event == "s")
    {
        m_model->movePlayer(0, -Joueur::JOUEUR_Y_SPEED);
    }
    else if (event == "droite" || event == "d")
    {
        m_model->movePlayer(Joueur::JOUEUR_X_SPEED, 0);
    }
    else if (event == "gauche" || event == "q")
    {
        m_model->movePlayer(-Joueur::JOUEUR_X_SPEED,0);
    }
    else if (event == "tir" || event == "&" || event == "1")
    {
        m_model->tirPlayer();
    }

    return retour;
}
