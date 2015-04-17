#include <iostream>
#include <cstdlib>

#include "TirAllie.h"

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


