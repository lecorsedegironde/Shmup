#include <iostream>
#include <cstdlib>
#include "Ennemi.h"

using namespace std;
//=============================================
//  Constantes                                |
//=============================================
const int Ennemi::W_SOLDIER = 120;
const int Ennemi::H_SOLDIER = 78;
const int Ennemi::W_TANK = 120;
const int Ennemi::H_TANK = 76;
const int Ennemi::W_SCOUT = 120;
const int Ennemi::H_SCOUT = 75;
const int Ennemi::W_SNIPER = 121;
const int Ennemi::H_SNIPER = 135;
const int Ennemi::SPEED_ENNEMI = -10;


//=============================================
//  Constructeurs                             |
//=============================================
Ennemi::Ennemi()
    : Vaisseau {}, m_idEnnemi {0},m_dommages {0}, m_modificateurVitesse {0}, m_cadenceTir {0}, m_valeur {0}
{}

Ennemi::Ennemi(int x, int y, int w, int h, int dx, unsigned int pdv,
               unsigned int id, TypeEnnemi type, int dom, int mVit, int tir, int val)
    : Vaisseau {x, y, w, h, dx, 0, pdv}, m_idEnnemi {id}, m_type {type}, m_dommages {dom},
m_modificateurVitesse {mVit}, m_cadenceTir {tir}, m_valeur {val}
{}
//=============================================
//  Destructeurs                              |
//=============================================
Ennemi::~Ennemi() {}

//=============================================
//  Getters                                   |
//=============================================
unsigned int Ennemi::getId() const
{
    return m_idEnnemi;
}

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

TypeEnnemi Ennemi::getType()
{
    return m_type;
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
