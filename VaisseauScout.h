#ifndef VAISSEAUSCOUT_H_INCLUDED
#define VAISSEAUSCOUT_H_INCLUDED

#include "Ennemi.h"

class VaisseauScout : public Ennemi
{
private:

public:
    VaisseauScout();
    VaisseauScout(int x, int y, int w, int h, int dx, int dy, unsigned int id, unsigned int pdv, int dom, int mVit, int tir, int val);
    virtual ~VaisseauScout();

};

#endif // VAISSEAUSCOUT_H_INCLUDED
