#include <iostream>
#include <cstdlib>

#include "TirAllie.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
TirAllie::TirAllie()
    : Tir {}
{
}

TirAllie::TirAllie(int x, int y, int w, int h, int dx, int dy, unsigned int id, int degats, int delai)
    : Tir {x, y, w, h, dx, dy, id, degats, delai}
{
}

TirAllie::~TirAllie()
{
}


