#ifndef VAISSEAU_H
#define VAISSEAU_H

#include <SFML/System.hpp>

#include "MovableElement.h"


class Vaisseau : public MovableElement
{
protected:
    unsigned int m_pointDeVie;
    sf::Clock m_clock;

public:
    Vaisseau();
    Vaisseau(int x, int y, int w, int h, int dx, int dy, unsigned int pdv);
    virtual ~Vaisseau();

    unsigned int getPointDeVie() const;
    float getElapsedTime();

    void setPointDeVie(const unsigned int &pdv);


    virtual void augmenterPv(const int &pdv);
    virtual void diminuerPv(const int &pdv);
    void resetClock();
};

#endif // VAISSEAU_H
