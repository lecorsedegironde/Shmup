#include <iostream>
#include <cstdlib>

#include "Bonus.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================

Bonus::Bonus()
    : MovableElement{}, m_id {0}
{}

Bonus::Bonus(int x, int y, int w, int h, int dx, int dy, unsigned int id)
    : MovableElement{x, y, w, h, dx, dy}, m_id {id}
{}

//=============================================
//  Destructeurs                              |
//=============================================

Bonus::~Bonus(){}

//=============================================
//  Getters                                   |
//=============================================

unsigned int Bonus::getId() const
{
    return m_id;
}

//=============================================
//  Setters                                   |
//=============================================

void Bonus::setId(const unsigned int &id)
{
    m_id = id;
}
