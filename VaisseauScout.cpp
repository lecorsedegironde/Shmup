#include <iostream>
#include <cstdlib>

#include "VaisseauScout.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
VaisseauScout::VaisseauScout()
    : Ennemi {}
{}

VaisseauScout::VaisseauScout(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, unsigned int id, int dom, int mVit, int tir, int val)
    : Ennemi {x, y, w, h, dx, dy, pdv, id, dom, mVit, tir, val}
{}

VaisseauScout::~VaisseauScout()
{}


