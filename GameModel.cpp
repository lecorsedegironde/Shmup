#include "GameModel.h"

using namespace std;

//*********************************************
//  Constantes                                *
//*********************************************
const int GameModel::MAX_BEST_SCORES = 5;
const int GameModel::MODEL_WIDTH = 800;
const int GameModel::MODEL_HEIGHT = 600;

//*********************************************
//* Constructeurs                             *
//*********************************************
GameModel::GameModel()
    : _w {MODEL_WIDTH}, _h {MODEL_HEIGHT}, _score{0},
    _malus{0}, _scoreTotal{0}, _combo{0}, _nbLevel{0},
    _quit{false}, _statusJeu{0}, _difficulty{0}, _start{clock()}
{
    //TODO Ici initialiser les classes qui ont des relations avec le GameModel
}

GameModel::GameModel(int w, int h)
    : _w {w}, _h {h}, _score{0}, _malus{0},
    _scoreTotal{0}, _combo{0}, _nbLevel{0},
    _quit{false}, _statusJeu{0}, _difficulty{0}, _start{clock()}
{
    //TODO Ici initialiser les classes qui ont des relations avec le GameModel
}

GameModel::GameModel(int w, int h, int d)
    :_w {w}, _h {h}, _score{0}, _malus{0},
    _scoreTotal{0}, _combo{0}, _nbLevel{0},
    _quit{false}, _statusJeu{0}, _difficulty {d}, _start{clock()}
{
    //TODO Ici initialiser les classes qui ont des relations avec le GameModel
}

//*********************************************
//* Destructeurs                              *
//*********************************************
GameModel::~GameModel()
{
    //TODO Detruire chaque objet initialisé dans le constructeur
}

//*********************************************
//* Prochaine Etape                           *
//*********************************************
void GameModel::nextStep()
{

    //C'est ici que l'on gère le jeu
    //Tous les ARR
    //Tous les déplacements
    //...

}

