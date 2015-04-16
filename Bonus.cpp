#include <iostream>
#include <cstdlib>

#include "Bonus.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================

Bonus::Bonus()
    : MovableElement{}
{}

Bonus::Bonus(int x, int y, int w, int h, int dx, int dy)
    : MovableElement{x, y, w, h, dx, dy}
{}

//=============================================
//  Destructeurs                              |
//=============================================

Bonus::~Bonus(){}

//=============================================
//  Getters                                   |
//=============================================


//=============================================
//  Setters                                   |
//=============================================
