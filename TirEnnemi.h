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

    TirEnnemi();
    TirEnnemi(int x, int y, int w, int h, int dx, int degats, unsigned int idEnnemi);
    virtual ~TirEnnemi();

    virtual bool estAmi(Vaisseau * v);
};

#endif // TIRENNEMI_H_INCLUDED
