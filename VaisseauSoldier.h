#ifndef VAISSEAUSOLDIER_H_INCLUDED
#define VAISSEAUSOLDIER_H_INCLUDED

#include "Ennemi.h"

class VaisseauSoldier : public Ennemi
{
private:

public:
    VaisseauSoldier();
    VaisseauSoldier(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, unsigned int id, int dom, int mVit, int tir, int val);
    virtual ~VaisseauSoldier();

};

#endif // VAISSEAUSOLDIER_H_INCLUDED
