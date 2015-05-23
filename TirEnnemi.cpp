#include <iostream>
#include <cstdlib>

#include "TirEnnemi.h"
#include "Ennemi.h"

using namespace std;

//=============================================
//  Constantes                                |
//=============================================
const int TirEnnemi::TIR_ENNEMI_SPEED = -15;
const int TirEnnemi::DMG_SOLDIER = 20;
const int TirEnnemi::DMG_TANK = 10;
const int TirEnnemi::DMG_SCOUT = 10;
const int TirEnnemi::DMG_SNIPER = 30;
const float TirEnnemi::CADENCE_SOLDIER = 1;
const float TirEnnemi::CADENCE_TANK = 1;
const float TirEnnemi::CADENCE_SCOUT = 0.9;
const float TirEnnemi::CADENCE_SNIPER = 1.5;

//=============================================
//  Constructeurs                             |
//=============================================
TirEnnemi::TirEnnemi()
    : Tir {}
{}

TirEnnemi::TirEnnemi(int x, int y, int w, int h, int dx,
                     int degats, unsigned int idEnnemi)
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
