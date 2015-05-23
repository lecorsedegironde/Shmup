#ifndef TIRENNEMI_H_INCLUDED
#define TIRENNEMI_H_INCLUDED

#include "Tir.h"
#include "Vaisseau.h"

class TirEnnemi : public Tir
{
private:
    unsigned int m_idEnnemi;
public:
    static const int TIR_ENNEMI_SPEED;
    static const int DMG_SOLDIER;
    static const int DMG_TANK;
    static const int DMG_SCOUT;
    static const int DMG_SNIPER;
    static const float CADENCE_SOLDIER;
    static const float CADENCE_TANK;
    static const float CADENCE_SCOUT;
    static const float CADENCE_SNIPER;

    TirEnnemi();
    TirEnnemi(int x, int y, int w, int h, int dx, int degats,
              unsigned int idEnnemi);
    virtual ~TirEnnemi();

    virtual bool estAmi(Vaisseau * v);
};

#endif // TIRENNEMI_H_INCLUDED
