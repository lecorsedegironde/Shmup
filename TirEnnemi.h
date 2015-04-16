#ifndef TIRENNEMI_H_INCLUDED
#define TIRENNEMI_H_INCLUDED

#include "Tir.h"

class TirEnnemi : public Tir
{
private:

public:
    TirEnnemi();
    TirEnnemi(int x, int y, int w, int h, int dx, int dy, unsigned int id, int degats, int delai);
    virtual ~TirEnnemi();

};

#endif // TIRENNEMI_H_INCLUDED
