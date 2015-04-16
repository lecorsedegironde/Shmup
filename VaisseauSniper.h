#ifndef VAISSEAUSNIPER_H_INCLUDED
#define VAISSEAUSNIPER_H_INCLUDED

#include "Ennemi.h"

class VaisseauSniper : public Ennemi
{
private:

public:
    VaisseauSniper();
    VaisseauSniper(int x, int y, int w, int h, int dx, int dy, unsigned int id, unsigned int pdv, int dom, int mVit, int tir, int val);
    virtual ~VaisseauSniper();

};

#endif // VAISSEAUSNIPER_H_INCLUDED
