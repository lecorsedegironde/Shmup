#include <iostream>
#include <cstdlib>

#include "Vaisseau.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
Vaisseau::Vaisseau()
    : MovableElement {}, m_idVaisseau {0}, m_pointDeVie {0}
{}

Vaisseau::Vaisseau(int x, int y, int w, int h, int dx, int dy, unsigned int id, unsigned int pdv)
    : MovableElement {x, y, w, h, dx, dy}, m_idVaisseau {id}, m_pointDeVie {pdv}
{}

//=============================================
//  Destructeurs                              |
//=============================================
Vaisseau::~Vaisseau() {}

//=============================================
//  Getters                                   |
//=============================================
unsigned int Vaisseau::getIdVaisseau() const
{
    return m_idVaisseau;
}

unsigned int Vaisseau::getPointDeVie() const
{
    return m_pointDeVie;
}
//=============================================
//  Setters                                   |
//=============================================

void Vaisseau::setIdVaisseau(const unsigned int &id)
{
    m_idVaisseau = id;
}

void Vaisseau::setPointDeVie(const unsigned int &pdv)
{
    m_pointDeVie = pdv;
}

//=============================================
//  Fonctions                                 |
//=============================================

void Vaisseau::augmenterPv(const int &pdv)
{
    m_pointDeVie += pdv;
}

void Vaisseau::diminuerPv(const int &pdv)
{
    m_pointDeVie -= pdv;
}
