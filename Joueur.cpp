#include <iostream>
#include <cstdlib>

#include "Joueur.h"

using namespace std;

//=============================================
//  Constantes                                |
//=============================================
const int Joueur::JOUEUR_WIDTH = 1;
const int Joueur::JOUEUR_HEIGHT = 1;
const int Joueur::JOUEUR_X_SPEED = 1;
const int Joueur::JOUEUR_Y_SPEED = 1;
const int Joueur::JOUEUR_BASE_PV = 100;
const int Joueur::JOUEUR_BASE_VIE = 3;
const int Joueur::JOUEUR_BASE_SHIELD = 0;
const int Joueur::JOUEUR_BASE_DEGATS = 10;
const int Joueur::JOUEUR_BASE_DELAI = 1;


//=============================================
//  Constructeurs                             |
//=============================================
Joueur::Joueur()
    : Vaisseau {}, m_nbVie {0}, m_shield {0}
{}

Joueur::Joueur(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, unsigned int vie, unsigned int s)
    :Vaisseau {x, y, w, h, dx, dy, pdv,}, m_nbVie {vie}, m_shield {s}
{}

//=============================================
//  Destructeurs                              |
//=============================================
Joueur::~Joueur() {}

//=============================================
//  Getters                                   |
//=============================================
unsigned int Joueur::getNbVie() const
{
    return m_nbVie;
}

unsigned int Joueur::getShield() const
{
    return m_shield;
}

//=============================================
//  Setters                                   |
//=============================================
void Joueur::setNbVie(const unsigned int &vie)
{
    m_nbVie = vie;
}

void Joueur::setShield(const unsigned int &s)
{
    m_shield = s;
}

//=============================================
//  Fonctions                                 |
//=============================================
void Joueur::perdreVie()
{
    m_nbVie--;
}

void Joueur::gagnerVie()
{
    m_nbVie++;
}

void Joueur::ameliorerVaisseau()
{
    //TODO Définir et implémenter l'interface d'amélioration du joueur
}

void Joueur::addTir(TirAllie *t)
{
    m_tirs.push_back(t);
}

string Joueur::toString()
{
    string str = Vaisseau::toString();
    str += "Nombre de vies : " + to_string(m_nbVie) + "\n";
    str += "Bouclier : " + to_string(m_shield) + "\n";

    return str;
}
