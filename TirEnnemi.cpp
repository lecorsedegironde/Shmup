#include <iostream>
#include <cstdlib>

#include "TirEnnemi.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
TirEnnemi::TirEnnemi()
    : Tir{}
{}

TirEnnemi::TirEnnemi(int x, int y, int w, int h, int dx, int dy, int degats, int delai)
    : Tir{x, y, w, h, dx, dy, degats, delai}
{}

TirEnnemi::~TirEnnemi()
{}


