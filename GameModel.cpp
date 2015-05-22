#include "GameModel.h"
#include "Joueur.h"
#include <algorithm>
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
m_combo {0}, m_nbLevel {0}, m_statusJeu {StatusJeu::Menu}, m_difficulty {0}
{
    m_joueur = new Joueur();
}

GameModel::GameModel(int w, int h)
    : m_w {w}, m_h {h}, m_score {0},m_combo {0}, m_nbLevel {1},
m_statusJeu {StatusJeu::Menu}, m_difficulty {0}
{
    m_joueur = new Joueur(0, h/2, Joueur::JOUEUR_WIDTH, Joueur::JOUEUR_HEIGHT,
    0, 0, Joueur::JOUEUR_BASE_PV, 20
    /*Joueur::JOUEUR_BASE_VIE*/, Joueur::JOUEUR_BASE_SHIELD, Joueur::JOUEUR_BASE_DELAI);
}

GameModel::GameModel(int w, int h, int d)
    : m_w {w}, m_h {h}, m_score {0}, m_combo {0}, m_nbLevel {0},
m_statusJeu {StatusJeu::Menu}, m_difficulty {d}
{
    m_joueur = new Joueur(0, h/2, Joueur::JOUEUR_WIDTH, Joueur::JOUEUR_HEIGHT,
    0, 0, Joueur::JOUEUR_BASE_PV,
    Joueur::JOUEUR_BASE_VIE, Joueur::JOUEUR_BASE_SHIELD, Joueur::JOUEUR_BASE_DELAI);
}

//=============================================
//  Destructeurs                              |
//=============================================
GameModel::~GameModel()
{
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

    for (auto it : m_explosion)
    {
        if (it != nullptr)
            delete it;
    }
}

//=============================================
//  Prochaine Étape                           |
//=============================================
void GameModel::nextStep()
{
    //Est-ce qu'on a fini le niveau ?
    bool finNiveau = testFinNiveau();
    //Est-ce que le joueur est encore en état de voler ?
    bool finJeu = testFinJeu();
    //Est-ce qu'il reste encore des explosions à afficher ?
    bool isExplosionAlive = areExplosionAlive();


    //On teste que le jeu ne soit pas fini
    if (!finNiveau && !finJeu)
    {
        //Le statut est à play
        //m_statusJeu = StatusJeu::Play;

        //On effectue les déplacements
        m_joueur->setX(m_joueur->getX() + m_joueur->getDx());
        m_joueur->setY(m_joueur->getY()+ m_joueur->getDy());

        isOnScreen(m_joueur);

        for (auto it : m_ennemi)
        {
            //L'ennemi sort de l'écran ?
            it->setEtat(isOnScreen(it));

            it->setX(it->getX() + it->getDx());
            it->setY(it->getY() + it->getDy());
        }

        for (auto it : m_tirs)
        {
            //Le tir sort de l'écran ?
            it->setEtat(isOnScreen(it));

            it->setX(it->getX() + it->getDx());
            it->setY(it->getY() + it->getDy());
        }

        for (auto it : m_explosion)
        {
            //L'explosion sort elle de l'écran ?
            it->setEtat(isOnScreen(it));

            //On met à jour le stade de l'explosion
            it->updateStade();

            it->setX(it->getX() + it->getDx());
            it->setY(it->getY() + it->getDy());
        }

        /**
        *
        * Les collisions
        *
        **/

        //
        // Collisions entre ennemis et le joueur
        //
        for (auto it : m_ennemi)
        {
            if(m_joueur->testCollision(it) && it->getEtat())
            {
                m_joueur->diminuerPv(it->getDommages());
                if (m_joueur->getPointDeVie() <= 0)
                {
                    playerLooseLife();
                }
                it->setEtat(false);
                m_score += it->getValeur();
            }
        }

        //
        // Collisions entre tirs et le joueur
        //
        for (auto it : m_tirs)
        {
            if(m_joueur->testCollision(it) && it->getEtat())
            {
                if (!it->estAmi(m_joueur))
                {
                    m_joueur->diminuerPv(it->getDegats());
                    if (m_joueur->getPointDeVie() <= 0)
                    {
                        playerLooseLife();
                    }
                    it->setEtat(false);
                }
            }
        }

        //
        // Collisions entre les tirs et les ennemis
        //
        for (auto itTir : m_tirs)
        {
            if (itTir->getEtat())
            {
                for (auto itEnnemi : m_ennemi)
                {
                    if (!itTir->estAmi(itEnnemi)  && itEnnemi->getEtat())
                    {
                        if (itTir->testCollision(itEnnemi))
                        {
                            itEnnemi->diminuerPv(itTir->getDegats());
                            itTir->setEtat(false);
                        }
                    }
                }
            }
        }


        //
        // Collisions entre ennemis
        //
        for (auto itEnnemi1 : m_ennemi)
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

        //
        // Collisions entre explosions et ennemis, explosions et tirs et explosion et joueur
        //

        for (auto itExplosion : m_explosion)
        {
            if (itExplosion->getEtat())
            {
                for (auto itEnnemi : m_ennemi)
                {
                    if (itExplosion->estLetale(itEnnemi))
                    {
                        itEnnemi->setEtat(false);
                    }
                }

                for (auto itTirs : m_tirs)
                {
                    if (itExplosion->estLetale(itTirs))
                    {
                        itTirs->setEtat(false);
                    }
                }

                if (itExplosion->estLetale(m_joueur))
                {
                    playerLooseLife();
                }

            }
        }

        //Pour chaque ennemi on check si ses PVs sont au dessus de 0
        for (auto it : m_ennemi)
        {
            if (it->getPointDeVie() <=0 && it->getEtat())
            {
                it->setEtat(false);
                m_score += it->getValeur();
            }
        }

        //Pour chaque ennemi, si son état est false, on ajoute une explosion
        //TODO Changer pour des valeurs plus affinées
        for (auto it : m_ennemi)
        {
            if (!it->getEtat())
            {
                Explosion * e = new Explosion(it->getX(), it->getY(), Explosion::TAILLE_EXPLOSION,
                                              Explosion::TAILLE_EXPLOSION, it->getDx(), Explosion::TAILLE_EXPLOSION);
                m_explosion.push_back(e);
            }
        }
    }
    else if (finNiveau && !finJeu)
    {
        //On a fini le niveau
        m_statusJeu = StatusJeu::PassLevel;

        m_nbLevel++;
        newLevel();
        finNiveau = false;
    }
    else if (finJeu && !isExplosionAlive)
    {
        //On a perdu la partie
        m_statusJeu = StatusJeu::LooseGame;
    }
    else if (isExplosionAlive && finJeu)
    {
        for (auto itEnnemi : m_ennemi)
        {
            if (itEnnemi->getEtat())
            {
                itEnnemi->setEtat(false);
                Explosion * e = new Explosion(itEnnemi->getX(), itEnnemi->getY(), Explosion::TAILLE_EXPLOSION,
                                              Explosion::TAILLE_EXPLOSION, 0, Explosion::TAILLE_EXPLOSION);
                m_explosion.push_back(e);

            }

        }
        for (auto itTirs : m_tirs)
        {
            itTirs->setEtat(false);
        }

        for (auto itExplosion : m_explosion)
        {
            //L'explosion sort elle de l'écran ?
            itExplosion->setEtat(isOnScreen(itExplosion));

            //On met à jour le stade de l'explosion
            itExplosion->updateStade();

            itExplosion->setX(itExplosion->getX() + itExplosion->getDx());
            itExplosion->setY(itExplosion->getY() + itExplosion->getDy());
        }
    }

    /**
    * Ici on retire les éléments qu'il n'y a plus besoin d'afficher
    **/
    auto itTirs = m_tirs.begin();
    for (; itTirs != m_tirs.end();)
    {
        if ( !(*itTirs)->getEtat())
        {
            delete *itTirs;
            itTirs = m_tirs.erase(itTirs);
        }
        else
            ++itTirs;
    }

    auto itEnnemi = m_ennemi.begin();
    for (; itEnnemi != m_ennemi.end();)
    {
        if ( !(*itEnnemi)->getEtat())
        {
            delete *itEnnemi;
            itEnnemi = m_ennemi.erase(itEnnemi);
        }
        else
            ++itEnnemi;
    }

    auto itExplosion = m_explosion.begin();
    for (; itExplosion != m_explosion.end();)
    {
        if ( !(*itExplosion)->getEtat())
        {
            delete *itExplosion;
            itExplosion = m_explosion.erase(itExplosion);
        }
        else
            ++itExplosion;
    }
}

//=============================================
//  Fonctions                                 |
//=============================================
void GameModel::tirPlayer()
{
    float time = m_clock.GetElapsedTime();
    if (time > m_joueur->getDelai())
    {
        int xTir = m_joueur->getX() + m_joueur->getH()/2;
        int yTir = m_joueur->getY() + m_joueur->getW()/2 - Tir::TIR_WIDTH/2;

        TirAllie * tirAllie = new TirAllie(xTir, yTir, Tir::TIR_HEIGHT, Tir::TIR_WIDTH, TirAllie::TIR_ALLIE_SPEED, m_joueur->JOUEUR_BASE_DEGATS);

        m_tirs.push_back(tirAllie);
        m_clock.Reset();
    }

}

void GameModel::tirEnnemi(Ennemi * e)
{
    //TODO Implémenter le tir des ennemis
    TirEnnemi * t = new TirEnnemi(e->getX(), e->getY(), 1, 1, -10, e->getDommages(), e->getId());
    m_tirs.push_back(t);
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

int GameModel::getScore() const
{
    return m_score;
}

StatusJeu GameModel::getStatus() const
{
    return m_statusJeu;
}

void GameModel::getInfo(unsigned int &pdv, unsigned int &vie) const
{
    pdv = m_joueur->getPointDeVie();
    vie = m_joueur->getNbVie();
}

vector<Tir*> GameModel::getTir() const
{
    return m_tirs;
}

vector<Ennemi*> GameModel::getEnnemi() const
{
    return m_ennemi;
}

vector<Explosion*> GameModel::getExplosion() const
{
    return m_explosion;
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

void GameModel::setStatus(const StatusJeu &s)
{
    m_statusJeu = s;
}

bool GameModel::testFinNiveau()
{
    bool finNiveau = false;

    if (m_ennemi.empty() && m_explosion.empty())
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
        if (m->getX() + m->getH() < 0 || m->getY() < 0 || m->getY() + m->getW() > heightScreen)
        {
            retour = false;
        }
    }
    else
    {
        if (m->getX() + m->getH() < 0 || m->getX() > widthScreen || m->getY() < 0 || m->getY() + m->getW() > heightScreen)
        {
            retour = false;
        }
    }
    return retour;
}

/**
* Ici on empêche le joueur de sortir de l'écran
**/
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

void GameModel::playerLooseLife()
{
    //On met le statut à LooseLife
    m_statusJeu = StatusJeu::LooseLife;

    m_joueur->perdreVie();

    for (auto itEnnemi : m_ennemi)
    {
        if (itEnnemi->getEtat())
        {
            itEnnemi->setEtat(false);
        }

    }
    for (auto itTirs : m_tirs)
    {
        itTirs->setEtat(false);
    }

    for (auto itExplosion : m_explosion)
    {
        itExplosion->setEtat(false);
    }

    resetPosJoueur();
    newLevel();

}

void GameModel::resetPosJoueur()
{
    setJoueurPos(0, m_h/2);
}

bool GameModel::isPlayerAlive()
{
    bool estVivant = true;

    if (m_joueur->getNbVie() == 0)
    {
        estVivant = false;
    }

    return estVivant;
}

bool GameModel::areExplosionAlive()
{
    bool isExplosionAlive = false;

    for (auto it : m_explosion)
    {
        if (!isExplosionAlive && it->getEtat())
            isExplosionAlive = true;
    }

    return isExplosionAlive;
}

void GameModel::newLevel()
{
    Level * l = new Level(m_nbLevel);
    setLevel(l);
    resetPosJoueur();
    delete l;
}
