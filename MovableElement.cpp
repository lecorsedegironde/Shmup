#include <iostream>
#include <cstdlib>

#include "MovableElement.h"
#include "GameModel.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
MovableElement::MovableElement()
    : m_x {0}, m_y {0}, m_w {0}, m_h {0}, m_dx {0},
m_dy {0}, m_etat {true}
{}

MovableElement::MovableElement(int x, int y, int w, int h,
                               int dx, int dy)
    : m_x {x}, m_y {y}, m_w {w}, m_h {h}, m_dx {dx},
m_dy {dy}, m_etat {true}
{}

//=============================================
//  Destructeurs                              |
//=============================================
MovableElement::~MovableElement() {}

//=============================================
//  Getters                                   |
//=============================================
int MovableElement::getX() const
{
    return m_x;
}

int MovableElement::getY() const
{
    return m_y;
}

int MovableElement::getW() const
{
    return m_w;
}

int MovableElement::getH() const
{
    return m_h;
}

int MovableElement::getDx() const
{
    return m_dx;
}

int MovableElement::getDy() const
{
    return m_dy;
}

bool MovableElement::getEtat() const
{
    return m_etat;
}

//=============================================
//  Setters                                   |
//=============================================
void MovableElement::setX(const int &x)
{
    m_x = x;
}

void MovableElement::setY(const int &y)
{
    m_y = y;
}

void MovableElement::setW(const int &w)
{
    m_w = w;
}

void MovableElement::setH(const int &h)
{
    m_h = h;
}

void MovableElement::setDx(const int &dx)
{
    m_dx = dx;
}

void MovableElement::setDy(const int &dy)
{
    m_dy = dy;
}

void MovableElement::setEtat(const bool &etat)
{
    m_etat = etat;
}

//=============================================
//  Fonctions                                 |
//=============================================
bool MovableElement::testCollision(MovableElement * m)
{
    bool collision = true;
    int xM = m->getX();
    int yM = m->getY();
    int wM = m->getW();
    int hM = m->getH();

    if ((xM >= m_x + m_w)          //Droite
            || (xM + wM <= m_x)    //Gauche
            || (yM >= m_y + m_h)   //Bas
            || (yM + hM <= m_y))   //Haut
    {
        collision = false;
    }
    return collision;
}
