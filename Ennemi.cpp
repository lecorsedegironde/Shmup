#include <iostream>
#include <cstdlib>
#include "Ennemi.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
Ennemi::Ennemi()
    : Vaisseau {}, m_dommages {0}, m_modificateurVitesse {0}, m_cadenceTir {0}, m_valeur {0}
{
    //TODO Ajouter le tir ennemi
}

Ennemi::Ennemi(int x, int y, int w, int h, int dx, int dy, unsigned int pdv,
                int dom, int mVit, int tir, int val)
    : Vaisseau {x, y, w, h, dx, dy, pdv}, m_dommages {dom},
m_modificateurVitesse {mVit}, m_cadenceTir {tir}, m_valeur {val}
{
    //TODO Ajouter le tir ennemi
}
//=============================================
//  Destructeurs                              |
//=============================================
Ennemi::~Ennemi() {}

//=============================================
//  Getters                                   |
//=============================================
int Ennemi::getDommages() const
{
    return m_dommages;
}

int Ennemi::getModificateurVitesse() const
{
    return m_modificateurVitesse;
}

int Ennemi::getCadenceTir() const
{
    return m_cadenceTir;
}

int Ennemi::getValeur() const
{
    return m_valeur;
}

//=============================================
//  Setters                                   |
//=============================================
void Ennemi::setDommages(const int &d)
{
    m_dommages = d;
}

void Ennemi::setModificateurVitesse(const int &mV)
{
    m_modificateurVitesse = mV;
}

void Ennemi::setCadenceTir(const int &c)
{
    m_cadenceTir = c;
}

void Ennemi::setValeur(const int &v)
{
    m_valeur = v;
}

//=============================================
//  Fonctions                                 |
//=============================================
void Ennemi::addTir(TirEnnemi * t)
{
    m_tirEnnemi.push_back(t);
}
