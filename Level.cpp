#include <iostream>
#include <cstdlib>

#include "Level.h"
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
    // TODO Remplacer par la génération aléatoire de level
    vector<Ennemi*> level;
    Ennemi * e = new Ennemi(500, 300, 1, 1, -10, 0, 20, 10, 0, 1, 10);

    level.push_back(e);

    return level;
}
