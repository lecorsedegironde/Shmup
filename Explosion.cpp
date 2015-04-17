#include <iostream>
#include <cstdlib>

#include "Explosion.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
Explosion::Explosion()
    : MovableElement {}, m_degats {0}, m_distanceLetale {0}
{}

Explosion::Explosion(int x, int y, int w, int h, int dx, int dy,
                     int degats, int distance)
    : MovableElement {x, y, w, h, dx, dy}, m_degats {degats},
m_distanceLetale {distance}
{}
//=============================================
//  Destructeurs                              |
//=============================================

Explosion::~Explosion() {}

//=============================================
//  Getters                                   |
//=============================================
int Explosion::getDegats() const
{
    return m_degats;
}

//=============================================
//  Setters                                   |
//=============================================
void Explosion::setDegats(const int &d)
{
    m_degats = d;
}

//=============================================
//  Fonctions                                 |
//=============================================

bool Explosion::estLetale(Vaisseau * v)
{
    bool retour = false;
    int xVaisseau = v->getX();
    int yVaisseau = v->getY();

    if (xVaisseau > m_x - m_distanceLetale && xVaisseau < m_x + m_distanceLetale && yVaisseau > m_y - m_distanceLetale && yVaisseau < m_x - m_distanceLetale)
    {
        retour = true;
    }

    return retour;
}
