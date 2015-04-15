#ifndef ENNEMI_H
#define ENNEMI_H

#include "Ennemi.h"
#include "Vaisseau.h"

class Ennemi : public Vaisseau
{
protected:
    int m_dommages;
    int m_modificateurVitesse;
    int m_cadenceTir;
    int m_valeur;
    //TODO Rajouter le tir ennemi
public:
    Ennemi();
    Ennemi(int x, int y, int w, int h, int dx, int dy, unsigned int id, unsigned int pdv, int dom, int mVit, int tir, int val);
    virtual ~Ennemi();

    int getDommages() const;
    int getModificateurVitesse() const;
    int getCadenceTir() const;
    int getValeur() const;

    void setDommages(const int &d);
    void setModificateurVitesse(const int &mV);
    void setCadenceTir(const int &c);
    void setValeur(const int &v);
};

#endif // ENNEMI_H
