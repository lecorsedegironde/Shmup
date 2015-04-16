#include <iostream>
#include <cstdlib>

#include "Vaisseau.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
Vaisseau::Vaisseau()
    : MovableElement {}, m_pointDeVie {0}
{}

Vaisseau::Vaisseau(int x, int y, int w, int h, int dx, int dy, unsigned int pdv)
    : MovableElement {x, y, w, h, dx, dy}, m_pointDeVie {pdv}
{}

//=============================================
//  Destructeurs                              |
//=============================================
Vaisseau::~Vaisseau() {}

//=============================================
//  Getters                                   |
//=============================================
unsigned int Vaisseau::getPointDeVie() const
{
    return m_pointDeVie;
}
//=============================================
//  Setters                                   |
//=============================================
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
