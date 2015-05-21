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
    m_joueur = new Joueur();
}

GameModel::GameModel(int w, int h)
    : m_w {w}, m_h {h}, m_score {0}, m_malus {0},
m_scoreTotal {0}, m_combo {0}, m_nbLevel {0},
m_quit {false}, m_statusJeu {0}, m_difficulty {0}, m_start {clock()}
{
    //TODO changer le pop du joueur
    m_joueur = new Joueur(w/2, h/2, Joueur::JOUEUR_WIDTH, Joueur::JOUEUR_HEIGHT,
    0, 0, Joueur::JOUEUR_BASE_PV,
    Joueur::JOUEUR_BASE_VIE, Joueur::JOUEUR_BASE_SHIELD);
}

GameModel::GameModel(int w, int h, int d)
    : m_w {w}, m_h {h}, m_score {0}, m_malus {0},
m_scoreTotal {0}, m_combo {0}, m_nbLevel {0},
m_quit {false}, m_statusJeu {0}, m_difficulty {d}, m_start {clock()}
{
    m_joueur = new Joueur(w/2, h/2, Joueur::JOUEUR_WIDTH, Joueur::JOUEUR_HEIGHT,
    0, 0, Joueur::JOUEUR_BASE_PV,
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

    for (auto it : m_ennemi)
    {
        if(it != nullptr)
            delete it;
    }

    for (auto it : m_tirs)
    {
        if(it != nullptr)
            delete it;
    }
}

//=============================================
//  Prochaine Étape                           |
//=============================================
void GameModel::nextStep()
{
    bool finNiveau = testFinNiveau();
    bool finJeu = testFinJeu();

    //On teste que le jeu ne soit pas fini
    if (!finNiveau && !finJeu)
    {
        //On effectue les déplacements
        m_joueur->setX(m_joueur->getX() + m_joueur->getDx());
        m_joueur->setY(m_joueur->getY()+ m_joueur->getDy());

        isOnScreen(m_joueur);

        for(auto it : m_ennemi)
        {
            //L'ennemi sort de l'écran ?
            it->setEtat(isOnScreen(it));

            it->setX(it->getX() + it->getDx());
            it->setY(it->getY()+ it->getDy());
        }

        for(auto it : m_tirs)
        {
            //Le tir sort de l'écran ?
            it->setEtat(isOnScreen(it));

            it->setX(it->getX() + it->getDx());
            it->setY(it->getY()+ it->getDy());
        }

        //On vérifie les collisions
        for (auto it : m_ennemi)    //Ennnemis <-> Joueur
        {
            if(m_joueur->testCollision(it) && it->getEtat())
            {
                m_joueur->diminuerPv(it->getDommages());
                it->setEtat(false);
            }
        }

        for (auto it : m_tirs)  //Tirs <-> Joueur
        {
            if(m_joueur->testCollision(it) && it->getEtat())
            {
                if (!it->estAmi(m_joueur))
                    m_joueur->diminuerPv(it->getDegats());
                it->setEtat(false);
            }
        }

        for (auto itTir : m_tirs)  //Tirs <-> Ennemis
        {
            if (itTir->getEtat())
            {
                for (auto itEnnemi : m_ennemi)
                {
                    if (!itTir->estAmi(itEnnemi)  && itEnnemi->getEtat() && itTir->testCollision(itEnnemi))
                    {
                        itEnnemi->diminuerPv(itTir->getDegats());
                        itTir->setEtat(false);
                    }
                }
            }
        }

        for (auto itEnnemi1 : m_ennemi) //Ennemi <-> Ennemi
        {
            if (itEnnemi1->getEtat())
            {
                for (auto itEnnemi2 : m_ennemi)
                {
                    if(itEnnemi1->testCollision(itEnnemi2) && itEnnemi1->getId() != itEnnemi2->getId())
                    {
                        itEnnemi1->setEtat(false);
                        itEnnemi2->setEtat(false);
                    }
                }
            }
        }

        //Pour chaque ennemi on check si ses pvs sont au dessus de 0
        for (auto it : m_ennemi)
        {
            if (it->getPointDeVie() <=0)
            {
                it->setEtat(false);
            }
        }

    }
    else
    {
        //TODO Virer ça !
        cout << "Niveau Fini" << endl << endl;
        nextLevel();
        finNiveau = false;
    }

    /**
    * Ici on retire les éléments qu'il n'y a plus besoin d'afficher
    **/
    int position = 0;
    vector<int> toDelete;

    for (auto it : m_tirs)
    {
        bool test = it->getEtat();
        if(!test)
        {
            toDelete.push_back(position);
        }
        position++;
    }

    for (auto i : toDelete)
    {
        delete m_tirs[i];
        m_tirs.erase(m_tirs.begin()+i);
    }
    toDelete.clear();

    position = 0;
    for (auto it : m_ennemi)
    {
        bool test = it->getEtat();
        if(!test)
        {
            m_ennemi.erase(m_ennemi.begin()+position);
            delete it;
        }
        position++;
    }
}

//=============================================
//  Fonctions                                 |
//=============================================
void GameModel::tirPlayer()
{
    TirAllie * tirAllie = new TirAllie(m_joueur->getX(), m_joueur->getY(), 1, 1, 10, 0, m_joueur->JOUEUR_BASE_DEGATS, m_joueur->JOUEUR_BASE_DELAI);

    m_tirs.push_back(tirAllie);
    m_joueur->addTir(tirAllie);
}

void GameModel::setLevel(Level * l)
{
    m_ennemi = l->genLevel();
}

void GameModel::getJoueurPos(int &x, int &y) const
{
    x = m_joueur->getX();
    y = m_joueur->getY();
}

void GameModel::getJoueurSize(int &w, int &h) const
{
    w = m_joueur->getW();
    h = m_joueur->getH();
}

void GameModel::getJoueurSpeed(int &dx, int &dy) const
{
    dx = m_joueur->getDx();
    dy = m_joueur->getDy();
}

vector<Tir*> GameModel::getTir() const
{
    return m_tirs;
}

vector<Ennemi*> GameModel::getEnnemi() const
{
    return m_ennemi;
}

void GameModel::setJoueurPos(const int &x, const int &y)
{
    m_joueur->setX(x);
    m_joueur->setY(y);
}

void GameModel::setJoueurSize(const int &w, const int &h)
{
    m_joueur->setW(w);
    m_joueur->setH(h);
}

void GameModel::setJoueurSpeed(const int &dx,const int &dy)
{
    m_joueur->setDx(dx);
    m_joueur->setDy(dy);
}

bool GameModel::testFinNiveau()
{
    bool finNiveau = false;

    if (m_ennemi.empty())
    {
        finNiveau = true;
    }

    return finNiveau;
}

bool GameModel::testFinJeu()
{
    bool finJeu = false;

    if (m_joueur->getNbVie() == 0 || !m_joueur->getEtat())
    {
        finJeu = true;
    }

    return finJeu;
}

/**
* Gestion de deux scénarios différents : ennemis qui peuvent avoir des y très élevés
* et les autres : scénario classique
**/
bool GameModel::isOnScreen(MovableElement * m)
{
    bool retour = true;
    int widthScreen = GameModel::MODEL_WIDTH;
    int heightScreen = GameModel::MODEL_HEIGHT;

    Ennemi * e = dynamic_cast<Ennemi*>(m);

    // Si c'est un ennemi
    if (e != nullptr)
    {
        if (m->getX() < 0 || m->getX() + m->getH() > widthScreen || m->getY() < 0)
        {
            retour = false;
        }
    }
    else
    {
        if (m->getX() < 0 || m->getX() + m->getH() > widthScreen || m->getY() < 0 || m->getY() + m->getW() > heightScreen)
        {
            retour = false;
        }
    }
    return retour;
}

/**
* Ici on empêche le joueur de sortir de l'écran
**/
//*
void GameModel::isOnScreen(Joueur * j)
{
    int widthScreen = GameModel::MODEL_WIDTH;
    int heightScreen = GameModel::MODEL_HEIGHT;

    if (j->getX() < 0)
    {
        j->setX(0);
    }

    if (j->getX() + j->getH() > widthScreen)
    {
        j->setX(widthScreen - j->getH());
    }
    if (j->getY() < 0)
    {
        j->setY(0);
    }
    if (j->getY() + j->getW() > heightScreen)
    {
        j->setY(heightScreen - j->getW());
    }
}
//*/
void GameModel::nextLevel()
{
    Level * l = new Level();
    setLevel(l);
    delete l;
}
