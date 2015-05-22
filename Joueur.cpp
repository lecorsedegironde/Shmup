#include <iostream>
#include <cstdlib>

#include "Joueur.h"

using namespace std;

//=============================================
//  Constantes                                |
//=============================================
const int Joueur::JOUEUR_WIDTH = 168;
const int Joueur::JOUEUR_HEIGHT = 74;
const int Joueur::JOUEUR_X_SPEED = 10;
const int Joueur::JOUEUR_Y_SPEED = 10;
const int Joueur::JOUEUR_BASE_PV = 100;
const int Joueur::JOUEUR_BASE_VIE = 3;
const int Joueur::JOUEUR_BASE_SHIELD = 0;
const int Joueur::JOUEUR_BASE_DEGATS = 10;
const float Joueur::JOUEUR_BASE_DELAI = 0.2;


//=============================================
//  Constructeurs                             |
//=============================================
Joueur::Joueur()
    : Vaisseau {}, m_nbVie {0}, m_shield {0}, m_delai {JOUEUR_BASE_DELAI}
{}

Joueur::Joueur(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, unsigned int vie, unsigned int s, float delai)
    :Vaisseau {x, y, w, h, dx, dy, pdv}, m_nbVie {vie}, m_shield {s}, m_delai {delai}
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

float Joueur::getDelai() const
{
    return m_delai;
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

void Joueur::setDelai(const float &d)
{
    m_delai = d;
}

//=============================================
//  Fonctions                                 |
//=============================================
void Joueur::perdreVie()
{
    if (m_nbVie > 0)
    {
        m_nbVie--;
        m_pointDeVie = JOUEUR_BASE_PV;
    }
}

void Joueur::gagnerVie()
{
    m_nbVie++;
    m_pointDeVie = JOUEUR_BASE_PV;
}
