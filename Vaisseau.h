#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "MovableElement.h"


class Vaisseau : public MovableElement
{
protected:
    unsigned int m_pointDeVie;

public:
    Vaisseau();
    Vaisseau(int x, int y, int w, int h, int dx, int dy, unsigned int pdv);
    virtual ~Vaisseau();

    unsigned int getPointDeVie() const;
    void setPointDeVie(const unsigned int &pdv);

    virtual void detruire() {}

    virtual void augmenterPv(const int &pdv);
    virtual void diminuerPv(const int &pdv);
};

#endif // VAISSEAU_H
