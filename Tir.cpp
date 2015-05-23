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

//=============================================
//  Constructeurs                             |
//=============================================

Tir::Tir()
    : MovableElement {}, m_degats {0}
{}

Tir::Tir(int x, int y, int w, int h, int dx, int degats)
    : MovableElement {x, y, w, h, dx, 0},
m_degats {degats}
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

//=============================================
//  Setters                                   |
//=============================================
void Tir::setDegats(const int &d)
{
    m_degats = d;
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
