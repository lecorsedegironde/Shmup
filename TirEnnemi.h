#ifndef TIRENNEMI_H_INCLUDED
#define TIRENNEMI_H_INCLUDED

#include "Tir.h"
#include "Vaisseau.h"

class TirEnnemi : public Tir
{
private:

public:
    TirEnnemi();
    TirEnnemi(int x, int y, int w, int h, int dx, int dy, int degats, int delai);
    virtual ~TirEnnemi();

    virtual bool estAmi(Vaisseau * v);
};

#endif // TIRENNEMI_H_INCLUDED
