#ifndef TIR_ALLIE_H_INCLUDED
#define TIR_ALLIE_H_INCLUDED


#include "Tir.h"

class TirAllie : public Tir
{
public:
    static const int TIR_ALLIE_SPEED;
    TirAllie();
    TirAllie(int x, int y, int w, int h, int dx, int degats);
    virtual ~TirAllie();

    virtual bool estAmi(Vaisseau * v);
};

#endif //TIR_ALLIE_H_INCLUDED
