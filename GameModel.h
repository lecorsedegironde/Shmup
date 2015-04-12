#ifndef GAME_MODEL_H
#define GAME_MODEL_H
#include <iostream>
#include <cstdlib>
#include <ctime>

class GameModel
{
private:
    //Constantes
    static const int MAX_BEST_SCORES;
    static const int MODEL_WIDTH;
    static const int MODEL_HEIGHT;

    //Données membres
    int _w;
    int _h;
    int _score;
    int _malus;
    int _scoreTotal;
    float _combo;
    int _nbLevel;
    bool _quit;
    int _statusJeu;
    int _difficulty;
    std::clock_t _start;

    //TODO Ajouter un argument ou un <vector> pour chaque classe reliée au GameModel

public:
    GameModel();
    GameModel(int w, int h);
    GameModel(int w, int h, int d);
    virtual ~GameModel();

    void nextStep();

    //A décommenter lorsque les classes correspondantes auront été ajoutées
    /*
    void movePlayer(Joueur * j);
    void tirPlayer(Joueur * j);
    bool testCollision(MovableEvent * m1, MovableEvent * m2);
    void detruireEnnemi(Ennemi * e);
    bool testFinNiveau();
    bool testFinJeu();
    void nextLevel();
    vector<Ennemi> genLevel();
    */
};

#endif // GAME_MODEL_H
