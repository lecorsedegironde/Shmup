#ifndef TIR_H
#define TIR_H

#include "MovableElement.h"
#include "Vaisseau.h"


class Tir : public MovableElement
{
protected:
    unsigned int m_id;
    int m_degats;
    int m_delai;

public:
    Tir();
    Tir(int x, int y, int w, int h, int dx, int dy, unsigned int id, int degats, int delai);
    virtual ~Tir();
    virtual bool estAmi(){return true;}

    unsigned int getId() const;
    int getDegats() const;
    int getDelai() const;

    void setId(const unsigned int &id);
    void setDegats(const int &d);
    void setDelai(const int &delai);

};

#endif // TIR_H
