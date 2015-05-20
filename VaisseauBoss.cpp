#include <iostream>
#include <cstdlib>

#include "VaisseauBoss.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
VaisseauBoss::VaisseauBoss()
    : Ennemi {}
{
}

VaisseauBoss::VaisseauBoss(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, unsigned int id, int dom, int mVit, int tir, int val)
    : Ennemi {x, y, w, h, dx, dy, pdv, id,dom, mVit, tir, val}
{
}

VaisseauBoss::~VaisseauBoss()
{
}


