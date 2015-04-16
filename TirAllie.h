#ifndef TIRENNEMI_H_INCLUDED
#define TIRENNEMI_H_INCLUDED

#include "Tir.h"

class TirAllie : public Tir
{
private:

public:
    TirAllie();
    TirAllie(int x, int y, int w, int h, int dx, int dy, unsigned int id, int degats, int delai);
    virtual ~TirAllie();

};

#endif // TIRENNEMI_H_INCLUDED
