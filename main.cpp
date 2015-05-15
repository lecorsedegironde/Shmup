#include <iostream>
#include "GameModel.h"
#include "GameView.h"
#include "Level.h"

using namespace std;

int main()
{
    //srand(time(NULL));

    GameModel * model = new GameModel(GameModel::MODEL_WIDTH, GameModel::MODEL_HEIGHT);
    GameView * view = new GameView(GameView::VIEW_W, GameView::VIEW_H, GameView::VIEW_BPP);

    Level * l = new Level();
    model->setLevel(l);

    view->setModel(model);



    while(view->treatEvents())
    {
        model->nextStep();
        view->draw();
    }

    delete view;
    delete model;
    delete l;

    return EXIT_SUCCESS;
}
