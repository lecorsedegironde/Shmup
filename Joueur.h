#ifndef JOUEUR_H
#define JOUEUR_H

#include "Vaisseau.h"


class Joueur : public Vaisseau
{
private:
    unsigned int m_nbVie;
    unsigned int m_shield;

public:
    Joueur();
    Joueur(int x, int y, int w, int h, int dx, int dy, unsigned int id, unsigned int pdv, unsigned int vie, unsigned int s);
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
