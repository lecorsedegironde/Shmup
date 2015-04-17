#include <iostream>
#include "GameModel.h"
#include "GameView.h"

using namespace std;

int main()
{
    GameModel * model = new GameModel(GameModel::MODEL_WIDTH, GameModel::MODEL_HEIGHT);
    GameView * view = new GameView(GameView::VIEW_W, GameView::VIEW_H);
    view->setModel(model);

    while(view->treatEvents())
    {
        //model->nextStep();
        view->draw();
    }

    delete view;
    delete model;

    return EXIT_SUCCESS;
}
