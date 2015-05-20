#ifndef VAISSEAUHEAVY_H_INCLUDED
#define VAISSEAUHEAVY_H_INCLUDED

#include "Ennemi.h"

class VaisseauHeavy : public Ennemi
{
private:

public:
    VaisseauHeavy();
    VaisseauHeavy(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, unsigned int id, int dom, int mVit, int tir, int val);
    virtual ~VaisseauHeavy();

};

#endif // VAISSEAUHEAVY_H_INCLUDED
