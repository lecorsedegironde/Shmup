#ifndef GAME_MODEL_H
#define GAME_MODEL_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "MovableElement.h"
#include "Joueur.h"
#include "Ennemi.h"

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
    //TODO Ajouter un argument ou un <vector> pour chaque classe reliée au GameModel

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


    //A décommenter lorsque les classes correspondantes auront été ajoutées
    //*
    void movePlayer(Joueur * j);
    void tirPlayer(Joueur * j);
    bool testCollision(MovableElement * m1, MovableElement * m2);
    void detruireEnnemi(Ennemi * e);
    bool testFinNiveau();
    bool testFinJeu();
    void nextLevel();
    std::vector<Ennemi> genLevel();
    //*/
};

#endif // GAME_MODEL_H
