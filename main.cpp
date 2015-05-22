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

//Tant que l'app tourne
    do
    {
        //On teste le statut du jeu
        switch (model->getStatus())
        {
        case StatusJeu::Play:
            while(view->treatEvents())
            {
                model->nextStep();
                view->draw();
            }
            break;
        case StatusJeu::Menu:
            while(view->treatMenuEvents())
            {
                view->drawMenu();
            }
            break;
        case StatusJeu::Pause:
            while(view->treatMenuEvents())
            {
                view->drawMenu();
            }
        case StatusJeu::LooseLife:
            view->drawTransition();
            break;
        case StatusJeu::LooseGame:
            view->drawTransition();
            break;
        case StatusJeu::PassLevel:
            view->drawTransition();
            break;
        case StatusJeu::Quit:
            break;
        default:
            while(view->treatEvents())
            {
                model->nextStep();
                view->draw();
            }
            break;
        }
    }
    while (model->getStatus() != Quit);


    delete view;
    delete model;
    delete l;

    return EXIT_SUCCESS;
}
