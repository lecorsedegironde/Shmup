#include <iostream>
#include <cstdlib>

#include "Explosion.h"

using namespace std;

//=============================================
//  Constantes                                |
//=============================================
const float Explosion::VITESSE_EXPLOSION = 0.1;
const int Explosion::TAILLE_EXPLOSION = 136;

//=============================================
//  Constructeurs                             |
//=============================================
Explosion::Explosion()
    : MovableElement {}, m_distanceLetale {0},
m_stade {StadeExplosion::Stade1}
{
    m_clock.Reset();
}

Explosion::Explosion(int x, int y, int w, int h, int dx,
                     int distance)
    : MovableElement {x, y, w, h, dx, 0}, m_distanceLetale {distance},
m_stade {StadeExplosion::Stade1}
{
    m_clock.Reset();
}

//=============================================
//  Destructeurs                              |
//=============================================

Explosion::~Explosion() {}

//=============================================
//  Getters                                   |
//=============================================
StadeExplosion Explosion::getStade() const
{
    return m_stade;
}

//=============================================
//  Setters                                   |
//=============================================
void Explosion::setStade(const StadeExplosion & s)
{
    m_stade = s;
}

//=============================================
//  Fonctions                                 |
//=============================================

bool Explosion::estLetale(MovableElement * m)
{
    bool isLetale = true;

    int xElement = m->getX();
    int yElement = m->getY();
    int wElement = m->getW();
    int hElement = m->getH();

    if ((xElement >= m_x + m_distanceLetale)          //Droite
            || (xElement + wElement <= m_x)    //Gauche
            || (yElement >= m_y + m_distanceLetale)   //Bas
            || (yElement + hElement <= m_y))   //Haut
    {
        isLetale = false;
    }

    return isLetale;
}

void Explosion::updateStade()
{
    float time = m_clock.GetElapsedTime();
    if (time > VITESSE_EXPLOSION)
    {
        switch (m_stade)
        {
        case StadeExplosion::Stade1:
            m_stade = StadeExplosion::Stade2;
            break;
        case StadeExplosion::Stade2:
            m_stade = StadeExplosion::Stade3;
            break;
        case StadeExplosion::Stade3:
            m_stade = StadeExplosion::Stade4;
            break;
        case StadeExplosion::Stade4:
            m_stade = StadeExplosion::Stade5;
            break;
        case StadeExplosion::Stade5:
            m_stade = StadeExplosion::Stade6;
            break;
        case StadeExplosion::Stade6:
            m_stade = StadeExplosion::Stade7;
            break;
        case StadeExplosion::Stade7:
            m_etat = false;
            break;
        default:
            m_stade = StadeExplosion::Stade1;
            break;
        }
        m_clock.Reset();
    }
}
