#include <iostream>
#include <cstdlib>

#include "Joueur.h"

using namespace std;

//=============================================
//  Constructeurs                             |
//=============================================
Joueur::Joueur()
    : Vaisseau {}, m_nbVie {0}, m_shield {0}
{
    //TODO Ajout des tirs alliés
}

Joueur::Joueur(int x, int y, int w, int h, int dx, int dy, unsigned int id, unsigned int pdv, unsigned int vie, unsigned int s)
    :Vaisseau {x, y, w, h, dx, dy, id, pdv,}, m_nbVie {vie}, m_shield {s}
{
    //TODO Ajout des tirs alliés
}

//=============================================
//  Destructeurs                              |
//=============================================
Joueur::~Joueur() {}

//=============================================
//  Getters                                   |
//=============================================
unsigned int Joueur::getNbVie() const
{
    return m_nbVie;
}

unsigned int Joueur::getShield() const
{
    return m_shield;
}

//=============================================
//  Setters                                   |
//=============================================
void Joueur::setNbVie(const unsigned int &vie)
{
    m_nbVie = vie;
}

void Joueur::setShield(const unsigned int &s)
{
    m_shield = s;
}

//=============================================
//  Fonctions                                 |
//=============================================
void Joueur::perdreVie()
{
    m_nbVie--;
}

void Joueur::gagnerVie()
{
    m_nbVie++;
}

void Joueur::ameliorerVaisseau()
{
    //TODO Définir et implémenter l'interface d'amélioration du joueur
}
