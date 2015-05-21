#include <iostream>
#include <cstdlib>

#include "Level.h"
#include "Ennemi.h"
using namespace std;


Level::Level()
    : m_difficulte {0}
{}

Level::Level(unsigned int difficulte)
    : m_difficulte {difficulte}
{}

Level::Level(const Level& l)
    : m_difficulte {l.getDifficulte()}
{}

Level::~Level()
{}

unsigned int Level::getDifficulte() const
{
    return m_difficulte;
}

void Level::setDifficulte(const unsigned int &d)
{
    m_difficulte = d;
}

vector<Ennemi*> Level::genLevel()
{
    int idEnnemi = 0;
    // TODO Remplacer par la génération aléatoire de level
    vector<Ennemi*> level;
    Ennemi * e1 = new Ennemi(500, 300, 1, 1, -10, 0, 20, idEnnemi, TypeEnnemi::Soldier, 10, 0, 1, 10);
    idEnnemi++;

    Ennemi * e2 = new Ennemi(700, 400, 1, 1, -10, 0, 20, idEnnemi, TypeEnnemi::Scout, 10, 0, 1, 10);
    idEnnemi++;

    level.push_back(e1);
    level.push_back(e2);

    return level;
}
