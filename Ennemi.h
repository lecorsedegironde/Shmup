#ifndef ENNEMI_H
#define ENNEMI_H

#include "Vaisseau.h"
#include "TirEnnemi.h"

enum TypeEnnemi {Soldier, Scout, Heavy, Sniper, Boss};

class Ennemi : public Vaisseau
{
private:
    unsigned int m_idEnnemi;
    TypeEnnemi m_type;
    int m_dommages;
    float m_cadenceTir;
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
    static const int VALEUR_SOLDIER;
    static const int VALEUR_TANK;
    static const int VALEUR_SCOUT;
    static const int VALEUR_SNIPER;
    static const int LIFE_SOLDIER;
    static const int LIFE_TANK;
    static const int LIFE_SCOUT;
    static const int LIFE_SNIPER;


    Ennemi();
    Ennemi(int x, int y, int w, int h, int dx, unsigned int pdv, unsigned int id, TypeEnnemi type, int dom, float tir, int val);
    virtual ~Ennemi();

    unsigned int getId() const;
    int getDommages() const;
    float getCadenceTir() const;
    int getValeur() const;
    TypeEnnemi getType();

    void setDommages(const int &d);
    void setCadenceTir(const float &c);
    void setValeur(const int &v);
    void setId(const unsigned int &id);
};

#endif // ENNEMI_H
