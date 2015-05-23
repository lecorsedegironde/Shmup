#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/System.hpp>

#include "MovableElement.h"

enum StadeExplosion {Stade1, Stade2, Stade3, Stade4,
                     Stade5, Stade6, Stade7
                    };

class Explosion : public MovableElement
{
private:
    //Les constantes privés
    static const float VITESSE_EXPLOSION;

    unsigned int m_id;
    int m_distanceLetale;
    StadeExplosion m_stade;
    sf::Clock m_clock;

public:
    //Constante publique
    static const int TAILLE_EXPLOSION;

    Explosion();
    Explosion(int x, int y, int w, int h, int dx, int distancce);
    virtual ~Explosion();
    bool estLetale(MovableElement * m);
    void updateStade();

    StadeExplosion getStade() const;
    void setStade(const StadeExplosion & s);

};

#endif // EXPLOSION_H
