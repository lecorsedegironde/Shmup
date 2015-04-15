#include <iostream>
#include <cstdlib>

#include "Tir.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================

Tir::Tir()
    : MovableElement{}, m_id{0}, m_degats{0}, m_delai{0}
{}

Tir::Tir(int x, int y, int w, int h, int dx, int dy, unsigned int id, int degats, int delai)
    : MovableElement{x, y, w, h, dx, dy}, m_id {id}, m_degats {degats}, m_delai {delai}
{}

//=============================================
//  Destructeurs                              |
//=============================================

Tir::~Tir() {}

//=============================================
//  Getters                                   |
//=============================================

unsigned int Tir::getId() const
{
    return m_id;
}

int Tir::getDegats() const
{
    return m_degats;
}

int Tir::getDelai() const
{
    return m_delai;
}

//=============================================
//  Setters                                   |
//=============================================

void Tir::setId(const unsigned int &id)
{
    m_id = id;
}

void Tir::setDegats(const int &d)
{
    m_degats = d;
}

void Tir::setDelai(const int &delai)
{
    m_delai = delai;
}
