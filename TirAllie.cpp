#include <iostream>
#include <cstdlib>

#include "TirAllie.h"
#include "Joueur.h"

using namespace std;

//=============================================
//  Constantes                                |
//=============================================
const int TirAllie::TIR_ALLIE_SPEED = 20;

//=============================================
//  Constructeurs                             |
//=============================================
TirAllie::TirAllie()
    : Tir {}
{}

TirAllie::TirAllie(int x, int y, int w, int h,
                   int dx, int degats)
    : Tir {x, y, w, h, dx, degats}
{}

TirAllie::~TirAllie()
{}

bool TirAllie::estAmi(Vaisseau * v)
{
    bool ami = false;

    Joueur * j = dynamic_cast<Joueur*>(v);

    if (j != nullptr)
    {
        ami = true;
    }

    return ami;
}
