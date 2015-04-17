#ifndef TIR_ALLIE_H_INCLUDED
#define TIR_ALLIE_H_INCLUDED


#include "Tir.h"

class TirAllie : public Tir
{
private:

public:
    TirAllie();
    TirAllie(int x, int y, int w, int h, int dx, int dy, int degats, int delai);
    virtual ~TirAllie();
};

#endif //TIR_ALLIE_H_INCLUDED
