#include <iostream>
#include <cstdlib>
#include "GameView.h"

using namespace std;

const int VIEW_W = 800;
const int VIEW_H = 600;
const int VIEW_BPP = 32;

GameView::GameView(int w, int h)
    : m_w{w}, m_h{h}
{}

GameView::~GameView()
{
    if (m_model != nullptr)
    {
        delete m_model;
    }
}


void GameView::setModel(GameModel * model)
{
    m_model = model;
}

void GameView::draw()
{
    //TODO Appeler les draw de chaque classe
}

void GameView::treatEvents()
{

}
