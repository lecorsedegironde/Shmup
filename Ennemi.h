#ifndef ENNEMI_H
#define ENNEMI_H

#include <vector>

#include "Ennemi.h"
#include "Vaisseau.h"
#include "TirEnnemi.h"

class Ennemi : public Vaisseau
{
protected:
    int m_dommages;
    int m_modificateurVitesse;
    int m_cadenceTir;
    int m_valeur;

    std::vector<TirEnnemi*> m_tirEnnemi;

public:
    Ennemi();
    Ennemi(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, int dom, int mVit, int tir, int val);
    virtual ~Ennemi();

    int getDommages() const;
    int getModificateurVitesse() const;
    int getCadenceTir() const;
    int getValeur() const;

    void setDommages(const int &d);
    void setModificateurVitesse(const int &mV);
    void setCadenceTir(const int &c);
    void setValeur(const int &v);

    void addTir(TirEnnemi * t);
    std::string toString();
};

#endif // ENNEMI_H
