#ifndef TIR_H
#define TIR_H

#include "MovableElement.h"
#include "Vaisseau.h"


class Tir : public MovableElement
{
protected:
    int m_degats;
    int m_delai;

public:
    //Constantes
    static const int TIR_WIDTH;
    static const int TIR_HEIGHT;
    static const int TIR_SPEED;

    Tir();
    Tir(int x, int y, int w, int h, int dx, int dy, int degats, int delai);
    virtual ~Tir();

    virtual bool estAmi(Vaisseau * v);

    int getDegats() const;
    int getDelai() const;

    void setDegats(const int &d);
    void setDelai(const int &delai);
};

#endif // TIR_H
