#include <iostream>
#include <cstdlib>

#include "TirAllie.h"
#include "Joueur.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
TirAllie::TirAllie()
    : Tir {}
{}

TirAllie::TirAllie(int x, int y, int w, int h, int dx, int dy, int degats, int delai)
    : Tir {x, y, w, h, dx, dy, degats, delai}
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

string TirAllie::toString()
{
    string str = Tir::toString();
    str += "Tir Ami\n";

    return str;
}
