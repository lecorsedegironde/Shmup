#include "GameModel.h"
#include "Joueur.h"
using namespace std;

//=============================================
//  Constantes                                |
//=============================================
const int GameModel::MAX_BEST_SCORES = 5;
const int GameModel::MODEL_WIDTH = 800;
const int GameModel::MODEL_HEIGHT = 600;

//=============================================
//  Constructeurs                             |
//=============================================
GameModel::GameModel()
    : m_w {MODEL_WIDTH}, m_h {MODEL_HEIGHT}, m_score {0},
m_malus {0}, m_scoreTotal {0}, m_combo {0}, m_nbLevel {0},
m_quit {false}, m_statusJeu {0}, m_difficulty {0}, m_start {clock()}
{
    //TODO Ici initialiser les classes qui ont des relations avec le GameModel
    m_joueur = new Joueur();
}

GameModel::GameModel(int w, int h)
    : m_w {w}, m_h {h}, m_score {0}, m_malus {0},
m_scoreTotal {0}, m_combo {0}, m_nbLevel {0},
m_quit {false}, m_statusJeu {0}, m_difficulty {0}, m_start {clock()}
{
    //TODO Ici initialiser les classes qui ont des relations avec le GameModel
    //TODO changer le pop du joueur
    m_joueur = new Joueur(w/2, h/2, Joueur::JOUEUR_WIDTH, Joueur::JOUEUR_HEIGHT,
    Joueur::JOUEUR_X_SPEED, Joueur::JOUEUR_Y_SPEED, Joueur::JOUEUR_BASE_PV,
    Joueur::JOUEUR_BASE_VIE, Joueur::JOUEUR_BASE_SHIELD);
}

GameModel::GameModel(int w, int h, int d)
    : m_w {w}, m_h {h}, m_score {0}, m_malus {0},
m_scoreTotal {0}, m_combo {0}, m_nbLevel {0},
m_quit {false}, m_statusJeu {0}, m_difficulty {d}, m_start {clock()}
{
    //TODO Ici initialiser les classes qui ont des relations avec le GameModel
    m_joueur = new Joueur(w/2, h/2, Joueur::JOUEUR_WIDTH, Joueur::JOUEUR_HEIGHT,
    Joueur::JOUEUR_X_SPEED, Joueur::JOUEUR_Y_SPEED, Joueur::JOUEUR_BASE_PV,
    Joueur::JOUEUR_BASE_VIE, Joueur::JOUEUR_BASE_SHIELD);
}

//=============================================
//  Destructeurs                              |
//=============================================
GameModel::~GameModel()
{
    //TODO Detruire chaque objet initialisé dans le constructeur
    if (m_joueur != nullptr)
    {
        delete m_joueur;
    }
}

//=============================================
//  Prochaine Etape                           |
//=============================================
void GameModel::nextStep()
{

    //C'est ici que l'on gère le jeu
    //Tous les ARR
    //Tous les déplacements
    //...

}

//=============================================
//  Fonctions                                 |
//=============================================
void GameModel::tirPlayer(Joueur * j)
{
    //TODO Remplacer w et h par les constantes correspondantes ensuite
    TirAllie * tirAllie = new TirAllie(j->getX(), j->getY(), 1, 1, 1, 1, j->JOUEUR_BASE_DEGATS, j->JOUEUR_BASE_DELAI);

    m_tirs.insert(tirAllie);
    j->addTir(tirAllie);

}

void GameModel::setLevel(Level * l)
{
    m_ennemi = l->genLevel();
}
