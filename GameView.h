#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "GameModel.h"

class GameView
{
private:
    int m_w;
    int m_h;

    static const int VIEW_W;
    static const int VIEW_H;
    static const int VIEW_BPP;

    GameModel * m_model;
public:
    GameView(int w, int h);
    ~GameView();

    void setModel(GameModel * model);
    void draw();
    void treatEvents();
};

#endif // GAMEVIEW_H
