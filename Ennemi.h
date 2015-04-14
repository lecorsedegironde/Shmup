#ifndef ENNEMI_H
#define ENNEMI_H

#include "Ennemi.h"


class Ennemi : public Ennemi
{
protected:
    int m_dommages;
    int m_modificateurVitesse;
    int m_cadenceTir;
    int m_valeur;
public:
    Ennemi();
    Ennemi(int x, int y, int w, int h, int dx, int dy, unsigned int id, unsigned int pdv, int dom, int mVit, int tir, int val);
    virtual ~Ennemi();

    int getDommages() const;
    int getModificateurVitesse() const;
    int getCadenceTir() const;
    int getValeur() const;

    void setDommages(const int &d);
};

#endif // ENNEMI_H
