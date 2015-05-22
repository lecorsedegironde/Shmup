#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <SFML/System.hpp>

#include "MovableElement.h"
#include "Joueur.h"
#include "Ennemi.h"
#include "Explosion.h"
#include "Level.h"

enum StatusJeu {Play, Pause, Menu, PassLevel, LooseLife, LooseGame, Quit};

class GameModel
{
private:
    //Données membres
    int m_w;
    int m_h;
    int m_score;
    float m_combo;
    unsigned int m_nbLevel;
    StatusJeu m_statusJeu;
    int m_difficulty;
    sf::Clock m_clock;

    //Joueur
    Joueur * m_joueur;

    //Ennemis
    std::vector<Ennemi*> m_ennemi;

    //Tirs
    std::vector<Tir*> m_tirs;

    //Explosions
    std::vector<Explosion*> m_explosion;

public:
    //Constantes
    static const int MAX_BEST_SCORES;
    static const int MODEL_WIDTH;
    static const int MODEL_HEIGHT;

    GameModel();
    GameModel(int w, int h);
    GameModel(int w, int h, int d);
    virtual ~GameModel();

    void nextStep();
    void setLevel(Level * l);

    void getJoueurPos(int &x, int &y) const;
    void getJoueurSize(int &w, int &h) const;
    void getJoueurSpeed(int &dx, int &dy) const;
    int getScore() const;
    StatusJeu getStatus() const;
    void getInfo(unsigned int &pdv, unsigned int &vie) const;

    std::vector<Tir*> getTir() const;
    std::vector<Ennemi*> getEnnemi() const;
    std::vector<Explosion*> getExplosion() const;

    void setJoueurPos(const int &x, const int &y);
    void setJoueurSize(const int &w, const int &h);
    void setJoueurSpeed(const int &dx, const int &dy);
    void setStatus(const StatusJeu &s);

    void tirPlayer();
    void tirEnnemi(Ennemi * e);

    bool testFinNiveau();
    bool testFinJeu();

    bool isOnScreen(MovableElement * m);
    void isOnScreen(Joueur * j);

    void playerLooseLife();
    void resetPosJoueur();
    bool isPlayerAlive();

    bool areExplosionAlive();

    void newLevel();
};



#endif // GAME_MODEL_H
