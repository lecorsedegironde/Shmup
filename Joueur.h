#ifndef JOUEUR_H
#define JOUEUR_H

#include "Vaisseau.h"
#include "TirAllie.h"

class Joueur : public Vaisseau
{
private:
    unsigned int m_nbVie;
    unsigned int m_shield;
    int m_degats;
    float m_delai;

public:
    //Les constantes :
    static const int JOUEUR_WIDTH;
    static const int JOUEUR_HEIGHT;
    static const int JOUEUR_X_SPEED;
    static const int JOUEUR_Y_SPEED;
    static const unsigned int JOUEUR_BASE_PV;
    static const int JOUEUR_BASE_VIE;
    static const int JOUEUR_BASE_SHIELD;
    static const int JOUEUR_BASE_DEGATS;
    static const float JOUEUR_BASE_DELAI;

    Joueur();
    Joueur(int x, int y, int w, int h, int dx, int dy,
           unsigned int pdv, unsigned int vie, unsigned int s,
           float delai);
    virtual ~Joueur();

    unsigned int getNbVie() const;
    unsigned int getShield() const;
    float getDelai() const;

    void setNbVie(const unsigned int &vie);
    void setShield(const unsigned int &s);
    void setDelai(const float &d);

    void perdreVie();
    void gagnerVie();
};

#endif // JOUEUR_H
