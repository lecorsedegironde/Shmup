#include <iostream>
#include <cstdlib>
#include "GameView.h"

using namespace std;

const int GameView::VIEW_W = 800;
const int GameView::VIEW_H = 600;
const int GameView::VIEW_BPP = 32;

GameView::GameView(int w, int h)
    : m_w{w}, m_h{h}
{}

GameView::~GameView()
{}


void GameView::setModel(GameModel * model)
{
    m_model = model;
}

void GameView::draw()
{
    //TODO Appeler les draw de chaque classe
    cout << m_model->toString() << endl;
}

bool GameView::treatEvents()
{
    bool retour = true;
    string event;

    cout << "====== JEU ======" << endl;
    cin >> event;
    cout << event << endl;

    if (event == "quit" || event == "q")
    {
        retour = false;
    }

    return retour;
}
