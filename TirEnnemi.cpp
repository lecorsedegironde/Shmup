#include <iostream>
#include <cstdlib>

#include "TirEnnemi.h"
#include "Ennemi.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
TirEnnemi::TirEnnemi()
    : Tir {}
{}

TirEnnemi::TirEnnemi(int x, int y, int w, int h, int dx, int dy, int degats, int delai, unsigned int idEnnemi)
    : Tir {x, y, w, h, dx, dy, degats, delai}, m_idEnnemi {idEnnemi}
{}

TirEnnemi::~TirEnnemi()
{}

bool TirEnnemi::estAmi(Vaisseau *v)
{
    bool ami = false;

    Ennemi * e = dynamic_cast<Ennemi*>(v);

    if (e != nullptr)
    {
        ami = true;
    }

    return ami;
}
