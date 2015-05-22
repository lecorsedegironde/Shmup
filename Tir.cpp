#include <iostream>
#include <cstdlib>

#include "Tir.h"
#include "Joueur.h"
#include "Ennemi.h"
#include "TirAllie.h"
#include "TirEnnemi.h"

using namespace std;
//=============================================
//  Constantes                                |
//=============================================
const int Tir::TIR_WIDTH = 10;
const int Tir::TIR_HEIGHT = 55;
const int Tir::TIR_SPEED = 10;


//=============================================
//  Constructeurs                             |
//=============================================

Tir::Tir()
    : MovableElement {}, m_degats {0}, m_delai {0}
{}

Tir::Tir(int x, int y, int w, int h, int dx, int dy, int degats, int delai)
    : MovableElement {x, y, w, h, dx, dy}, m_degats {degats}, m_delai {delai}
{}

//=============================================
//  Destructeurs                              |
//=============================================
Tir::~Tir() {}

//=============================================
//  Getters                                   |
//=============================================
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
void Tir::setDegats(const int &d)
{
    m_degats = d;
}

void Tir::setDelai(const int &delai)
{
    m_delai = delai;
}

//=============================================
//  Fonctions                                 |
//=============================================

bool Tir::estAmi(Vaisseau * v)
{
    bool ami = false;

    Joueur * j = dynamic_cast<Joueur*>(v);
    Ennemi * e = dynamic_cast<Ennemi*>(v);

    TirAllie * tA = dynamic_cast<TirAllie*>(this);
    TirEnnemi * tE = dynamic_cast<TirEnnemi*>(this);

    if (j != nullptr && tA != nullptr)
    {
        ami = true;
    }
    else if (e != nullptr && tE != nullptr)
    {
        ami = true;
    }

    return ami;
}
