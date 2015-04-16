#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "MovableElement.h"
#include "Vaisseau.h"


class Explosion : public MovableElement
{
private:
    unsigned int m_id;
    int m_degats;
    int m_distanceLetale;
public:
    Explosion();
    Explosion(int x, int y, int w, int h, int dx, int dy, int degats, int distancce);
    virtual ~Explosion();
    bool estLetale(Vaisseau * v);

    int getDegats() const;

    void setDegats(const int &d);
};

#endif // EXPLOSION_H
