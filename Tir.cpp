#include <iostream>
#include <cstdlib>

#include "Tir.h"
#include "Joueur.h"
#include "Ennemi.h"
#include "TirAllie.h"
#include "TirEnnemi.h"

using namespace std;

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
string Tir::toString()
{
    string str = "Position : (" + to_string(m_x) + "," + to_string(m_y) + ")\n";
    str += "Dégats : " + to_string(m_degats) + "\n";
    return str;
}

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
    else if (e != nullptr)
    {
        ami = true;
    }

    return ami;
}
