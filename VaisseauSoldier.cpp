#include <iostream>
#include <cstdlib>

#include "VaisseauSoldier.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
VaisseauSoldier::VaisseauSoldier()
    : Ennemi {}
{
}

VaisseauSoldier::VaisseauSoldier(int x, int y, int w, int h, int dx, int dy, unsigned int id, unsigned int pdv, int dom, int mVit, int tir, int val)
    : Ennemi {x, y, w, h, dx, dy, id, pdv, dom, mVit, tir, val}
{
}

VaisseauSoldier::~VaisseauSoldier()
{
}


