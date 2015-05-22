#include <iostream>
#include <cstdlib>

#include "TirEnnemi.h"
#include "Ennemi.h"

using namespace std;

//=============================================
//  Constantes                                |
//=============================================
const int TirEnnemi::TIR_ENNEMI_SPEED = -10;

//=============================================
//  Constructeurs                             |
//=============================================
TirEnnemi::TirEnnemi()
    : Tir {}
{}

TirEnnemi::TirEnnemi(int x, int y, int w, int h, int dx, int degats, unsigned int idEnnemi)
    : Tir {x, y, w, h, dx, degats}, m_idEnnemi {idEnnemi}
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
