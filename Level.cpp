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

Level& Level::operator=(const Level& l)
{
    //TODO Verifier
    if (this == &l) return *this; // handle self assignment
    //assignment operator
    return *this;
}

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
    Ennemi * e = new Ennemi();

    level.push_back(e);

    return level;
}
