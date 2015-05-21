#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "MovableElement.h"
#include "Joueur.h"
#include "Ennemi.h"
#include "Level.h"

class GameModel
{
private:
    //Données membres
    int m_w;
    int m_h;
    int m_score;
    int m_malus;
    int m_scoreTotal;
    float m_combo;
    int m_nbLevel;
    bool m_quit;
    int m_statusJeu;
    int m_difficulty;
    std::clock_t m_start;

    //Joueur
    Joueur * m_joueur;

    //Ennemis
    std::vector<Ennemi*> m_ennemi;

    //Tirs
    std::vector<Tir*> m_tirs;

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

    std::vector<Tir*> getTir() const;
    std::vector<Ennemi*> getEnnemi() const;

    void setJoueurPos(const int &x, const int &y);
    void setJoueurSize(const int &w, const int &h);
    void setJoueurSpeed(const int &dx, const int &dy);

    void tirPlayer();
    void tirEnnemi(Ennemi * e);

    bool testFinNiveau();
    bool testFinJeu();

    bool isOnScreen(MovableElement * m);
    void isOnScreen(Joueur * j);

    void nextLevel();
};

#endif // GAME_MODEL_H
