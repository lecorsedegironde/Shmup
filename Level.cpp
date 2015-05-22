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
    Ennemi * e1 = new Ennemi(900, 300, Ennemi::W_SOLDIER, Ennemi::H_SOLDIER,
        Ennemi::SPEED_ENNEMI, Ennemi::LIFE_SOLDIER, idEnnemi, TypeEnnemi::Soldier,
        TirEnnemi::DMG_SOLDIER, TirEnnemi::CADENCE_SOLDIER, Ennemi::VALEUR_SOLDIER);
    idEnnemi++;

    Ennemi * e2 = new Ennemi(1200, 400, Ennemi::W_SCOUT, Ennemi::H_SCOUT,
        Ennemi::SPEED_ENNEMI, Ennemi::LIFE_SCOUT, idEnnemi, TypeEnnemi::Scout,
        TirEnnemi::DMG_SCOUT, TirEnnemi::CADENCE_SCOUT, Ennemi::VALEUR_SCOUT);
    idEnnemi++;

    Ennemi * e3 = new Ennemi(1500, 400, Ennemi::W_TANK, Ennemi::H_TANK,
        Ennemi::SPEED_ENNEMI, Ennemi::LIFE_TANK, idEnnemi, TypeEnnemi::Heavy,
        TirEnnemi::DMG_TANK, TirEnnemi::CADENCE_TANK, Ennemi::VALEUR_TANK);
    idEnnemi++;

    Ennemi * e4 = new Ennemi(1800, 200, Ennemi::W_SNIPER, Ennemi::H_SNIPER,
        Ennemi::SPEED_ENNEMI, Ennemi::LIFE_SNIPER, idEnnemi, TypeEnnemi::Sniper,
        TirEnnemi::DMG_SNIPER, TirEnnemi::CADENCE_SNIPER, Ennemi::VALEUR_SNIPER);
    idEnnemi++;



    level.push_back(e1);
    level.push_back(e2);
    level.push_back(e3);
    level.push_back(e4);

    return level;
}
