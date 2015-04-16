#ifndef JOUEUR_H
#define JOUEUR_H

#include "Vaisseau.h"


class Joueur : public Vaisseau
{
private:
    unsigned int m_nbVie;
    unsigned int m_shield;

public:
    //Les constantes :
    static const int JOUEUR_WIDTH;
    static const int JOUEUR_HEIGHT;
    static const int JOUEUR_X_SPEED;
    static const int JOUEUR_Y_SPEED;
    static const int JOUEUR_BASE_PV;
    static const int JOUEUR_BASE_VIE;
    static const int JOUEUR_BASE_SHIELD;

    Joueur();
    Joueur(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, unsigned int vie, unsigned int s);
    virtual ~Joueur();

    unsigned int getNbVie() const;
    unsigned int getShield() const;
    void setNbVie(const unsigned int &vie);
    void setShield(const unsigned int &s);

    void perdreVie();
    void gagnerVie();
    void ameliorerVaisseau();
};

#endif // JOUEUR_H
