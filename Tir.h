#ifndef TIR_H
#define TIR_H

#include "MovableElement.h"
#include "Vaisseau.h"


class Tir : public MovableElement
{
protected:
    int m_degats;

public:
    //Constantes
    static const int TIR_WIDTH;
    static const int TIR_HEIGHT;

    Tir();
    Tir(int x, int y, int w, int h, int dx, int degats);
    virtual ~Tir();

    virtual bool estAmi(Vaisseau * v);

    int getDegats() const;

    void setDegats(const int &d);
};

#endif // TIR_H
