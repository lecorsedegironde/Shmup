#include <iostream>
#include <cstdlib>

#include "MovableElement.h"
#include "GameModel.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
MovableElement::MovableElement()
    : m_x {0}, m_y {0}, m_w {0}, m_h {0}, m_dx {0}, m_dy {0}, m_etat {true}
{}

MovableElement::MovableElement(int x, int y, int w, int h, int dx, int dy)
    : m_x {x}, m_y {y}, m_w {w}, m_h {h}, m_dx {dx}, m_dy {dy}, m_etat {true}
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
    //TODO Gestion des collisions
    //Pour l'affichage console, comme tous a pour taille (1,1), on se contente de tester les coordonnées
    bool collision = false;
    int xM = m->getX();
    int yM = m->getY();

    if (xM == m_x && yM == m_y)
    {
        collision = true;
    }

    return collision;
}

void MovableElement::isOnScreen()
{
    int widthScreen = GameModel::MODEL_WIDTH;
    int heightScreen = GameModel::MODEL_HEIGHT;

    if ((m_h < 0) || (m_h > heightScreen) || (m_w < 0) || (m_w > widthScreen))
    {
        m_etat = false;
    }

}

string MovableElement::toString()
{
    string str = "Position : ";
    str += "(" + to_string(m_x) + "," + to_string(m_y) + ")\n";
    str += "Taille : ";
    str += "(" + to_string(m_w) + "," + to_string(m_h) + ")\n";
    str += "Déplacement horizontal : " + to_string(m_dx) + "\n";
    str += "Déplacement vertical : " + to_string(m_dy) + "\n";
    str += "Etat : " + to_string(m_etat) + "\n";

    return str;
}
