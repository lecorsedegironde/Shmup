#include <iostream>
#include <cstdlib>

#include "Level.h"
#include "Ennemi.h"
#include "GameModel.h"
using namespace std;


Level::Level()
    : m_difficulte {1}
{}

Level::Level(unsigned int difficulte)
    : m_difficulte {(difficulte + 10) / 10}
{}

Level::Level(const Level& l)
    : m_difficulte {l.getDifficulte()}
{}

Level::~Level()
{}

float Level::getDifficulte() const
{
    return m_difficulte;
}

void Level::setDifficulte(const unsigned int &d)
{
    m_difficulte = (d + 10) / 10;
}

vector<Ennemi*> Level::genLevel()
{
    //Intervalle minimum entre les vaisseaux
    int interval = 100;
    //Intervalle maximum entre les vaisseaux
    //Position du premier ennemi
    int xStart = 800;
    //le y+h de l'ennemi < 600
    int yMaxSoldier = GameModel::MODEL_HEIGHT - Ennemi::H_SOLDIER;
    int yMaxScout = GameModel::MODEL_HEIGHT - Ennemi::H_SCOUT;
    int yMaxTank = GameModel::MODEL_HEIGHT - Ennemi::H_TANK;
    int yMaxSniper = GameModel::MODEL_HEIGHT - Ennemi::H_SNIPER;


    //A partir de la difficulté, on détermine le nombre d'ennemis
    //et le nombre max par types
    // Nombre de base : 50 pour difficulté = 1
    int nbEnnemi = (int)50*m_difficulte;
    int nbEnnemiRestant = nbEnnemi;

    //Nombre de Soldiers : 50%
    int nbSoldiers = (int)nbEnnemiRestant / 2;
    nbEnnemiRestant -= nbSoldiers;

    //Nombre de Scouts : 25% soit la moitié du reste
    int nbScouts = (int)nbEnnemiRestant / 2;
    nbEnnemiRestant -= nbScouts;

    //Nombre de Tanks : 15% soit 75% du reste
    int nbTanks = (int)nbEnnemiRestant * 0.75;
    nbEnnemiRestant -= nbTanks;

    //Nombre de Snipers : le reste
    int nbSnipers = nbEnnemiRestant;

    vector<Ennemi*> level;

    for (int i = 0 ; i < nbEnnemi ; i++)
    {
        bool succesGen = false;
        do
        {
            //On commence par déterminer le type de l'ennemi : 0 = Soldier, 1 = Scout, 2 = Tank, 3 = Sniper
            int type = rand() % 4;
            if (type == 0)  //Soldier
            {
                if (nbSoldiers > 0)
                {
                    //On génère un y :
                    int yStart = rand() % yMaxSoldier;
                    Ennemi * e1 = new Ennemi(xStart, yStart, Ennemi::W_SOLDIER, Ennemi::H_SOLDIER,
                                Ennemi::SPEED_ENNEMI, Ennemi::LIFE_SOLDIER, i, TypeEnnemi::Soldier,
                                TirEnnemi::DMG_SOLDIER, TirEnnemi::CADENCE_SOLDIER, Ennemi::VALEUR_SOLDIER);
                    level.push_back(e1);
                    nbSoldiers--;
                    succesGen = true;
                }
                else
                    succesGen = false;
            }
            else if (type == 1) //Scout
            {
                if (nbScouts > 0)
                {
                    //On génère
                    int yStart = rand() % yMaxScout;
                    Ennemi * e2 = new Ennemi(xStart, yStart, Ennemi::W_SCOUT, Ennemi::H_SCOUT,
                                Ennemi::SPEED_ENNEMI, Ennemi::LIFE_SCOUT, i, TypeEnnemi::Scout,
                                TirEnnemi::DMG_SCOUT, TirEnnemi::CADENCE_SCOUT, Ennemi::VALEUR_SCOUT);

                    level.push_back(e2);
                    nbScouts--;
                    succesGen = true;
                }
                else
                    succesGen = false;
            }
            else if (type == 2) //Tank
            {
                if (nbTanks > 0)
                {
                    //On génère
                    int yStart = rand() % yMaxTank;
                    Ennemi * e3 = new Ennemi(xStart, yStart, Ennemi::W_TANK, Ennemi::H_TANK,
                                Ennemi::SPEED_ENNEMI, Ennemi::LIFE_TANK, i, TypeEnnemi::Heavy,
                                TirEnnemi::DMG_TANK, TirEnnemi::CADENCE_TANK, Ennemi::VALEUR_TANK);
                    level.push_back(e3);
                    nbTanks--;
                    succesGen = true;
                }
                else
                    succesGen = false;
            }
            else if (type == 3) //Sniper
            {
                if (nbSnipers > 0)
                {
                    //On génère
                    int yStart = rand() % yMaxSniper;
                    Ennemi * e4 = new Ennemi(xStart, yStart, Ennemi::W_SNIPER, Ennemi::H_SNIPER,
                                Ennemi::SPEED_ENNEMI, Ennemi::LIFE_SNIPER, i, TypeEnnemi::Sniper,
                                TirEnnemi::DMG_SNIPER, TirEnnemi::CADENCE_SNIPER, Ennemi::VALEUR_SNIPER);

                    level.push_back(e4);
                    nbSnipers--;
                    succesGen = true;
                }
                else
                    succesGen = false;
            }
        }
        while(!succesGen); //Tant que la génération échoue

        //On augmente le xStart :
        xStart += interval;

    }

    return level;
}
