#ifndef VAISSEAUBOSS_H_INCLUDED
#define VAISSEAUBOSS_H_INCLUDED

#include "Ennemi.h"

class VaisseauBoss : public Ennemi
{
private:

public:
    VaisseauBoss();
    VaisseauBoss(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, unsigned int id, int dom, int mVit, int tir, int val);
    virtual ~VaisseauBoss();

};

#endif // VAISSEAUBOSS_H_INCLUDED
