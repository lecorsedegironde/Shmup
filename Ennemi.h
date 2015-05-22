#ifndef ENNEMI_H
#define ENNEMI_H

#include <vector>

#include "Vaisseau.h"
#include "TirEnnemi.h"

enum TypeEnnemi {Soldier, Scout, Heavy, Sniper, Boss};

class Ennemi : public Vaisseau
{
protected:
    unsigned int m_idEnnemi;
    TypeEnnemi m_type;
    int m_dommages;
    int m_modificateurVitesse;
    int m_cadenceTir;
    int m_valeur;

public:
    static const int W_SOLDIER;
    static const int H_SOLDIER;
    static const int W_TANK;
    static const int H_TANK;
    static const int W_SCOUT;
    static const int H_SCOUT;
    static const int W_SNIPER;
    static const int H_SNIPER;
    static const int SPEED_ENNEMI;

    Ennemi();
    Ennemi(int x, int y, int w, int h, int dx, int dy, unsigned int pdv, unsigned int id, TypeEnnemi type,int dom, int mVit, int tir, int val);
    virtual ~Ennemi();

    unsigned int getId() const;
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
