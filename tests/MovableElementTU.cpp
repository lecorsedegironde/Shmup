#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MovableElementTest

#include <boost/test/unit_test.hpp>
#include "../MovableElement.h"
#include "../Vaisseau.h"
#include "../Tir.h"
#include "../TirAllie.h"
#include "../TirEnnemi.h"
#include "../Joueur.h"
#include "../Ennemi.h"
#include "../Explosion.h"

BOOST_AUTO_TEST_CASE(movableElementTest)
{
    int x = 42;
    int y = 666;
    int w = 1664;
    int h = 420;
    int dx = 777;
    int dy = 380;

    MovableElement * m = new MovableElement();
    MovableElement * m1 = new MovableElement(x, y, w, h, dx, dy);

    BOOST_CHECK(m->getX() == 0);
    BOOST_CHECK(m->getY() == 0);
    BOOST_CHECK(m->getW() == 0);
    BOOST_CHECK(m->getH() == 0);
    BOOST_CHECK(m->getDx() == 0);
    BOOST_CHECK(m->getDy() == 0);
    m->setX(x);
    m->setY(y);
    m->setW(w);
    m->setH(h);
    m->setDx(dx);
    m->setDy(dy);
    BOOST_CHECK(m->getX() == x);
    BOOST_CHECK(m->getY() == y);
    BOOST_CHECK(m->getW() == w);
    BOOST_CHECK(m->getH() == h);
    BOOST_CHECK(m->getDx() == dx);
    BOOST_CHECK(m->getDy() == dy);

    BOOST_CHECK(m->getEtat() == true);
    m->setEtat(false);
    BOOST_CHECK(m->getEtat() == false);

    //On teste tout les cas où il y a collision
    BOOST_CHECK(m->testCollision(m1));
    m1->setX(x+w);
    m1->setY(y+h);
    BOOST_CHECK(!m->testCollision(m1));
    m1->setX(x);
    BOOST_CHECK(!m->testCollision(m1));
    m1->setX(x+w);
    m1->setY(y);
    BOOST_CHECK(!m->testCollision(m1));

    delete m;
    delete m1;
}

BOOST_AUTO_TEST_CASE(VaisseauTest)
{
    unsigned int pv = 10;
    Vaisseau * v = new Vaisseau();
    v->resetClock();

    BOOST_CHECK(v->getPointDeVie() == 0);
    v->setPointDeVie(pv);
    BOOST_CHECK(v->getPointDeVie() == pv);
    v->augmenterPv(1);
    BOOST_CHECK(v->getPointDeVie() == pv+1);
    v->diminuerPv(1);
    BOOST_CHECK(v->getPointDeVie() == pv);

    delete v;
}

BOOST_AUTO_TEST_CASE(TirsTest)
{
    //Test tirs de base
    int degats = 10;

    Tir * t = new Tir();
    Vaisseau * v = new Vaisseau();

    BOOST_CHECK(t->getDegats() == 0);
    t->setDegats(degats);
    BOOST_CHECK(t->getDegats() == degats);

    BOOST_CHECK(!t->estAmi(v));

    //Test tirs ami et ennemi
    TirAllie * tA = new TirAllie();
    TirEnnemi * tE = new TirEnnemi();
    Joueur * j = new Joueur();
    Ennemi * e = new Ennemi();

    BOOST_CHECK(tA->estAmi(j));
    BOOST_CHECK(!tA->estAmi(e));
    BOOST_CHECK(tE->estAmi(e));
    BOOST_CHECK(!tE->estAmi(j));

    delete t;
    delete v;
    delete tA;
    delete tE;
    delete j;
    delete e;
}

BOOST_AUTO_TEST_CASE(ExplosionTest)
{
    Explosion * e = new Explosion(1, 1, 1, 1, 0, 10);

    BOOST_CHECK(e->getStade() == StadeExplosion::Stade1);
    e->setStade(StadeExplosion::Stade2);
    BOOST_CHECK(e->getStade() == StadeExplosion::Stade2);
    e->updateStade();
    BOOST_CHECK(e->getStade() == StadeExplosion::Stade2);

    MovableElement * m = new MovableElement(1, 1, 1, 1, 0, 0);
    BOOST_CHECK(e->estLetale(m));
    m->setX(20);
    BOOST_CHECK(!e->estLetale(m));

    delete e;
    delete m;
}

BOOST_AUTO_TEST_CASE(JoueurTest)
{
    Joueur * j = new Joueur();

    unsigned int vie = 787;
    unsigned int shield = 42;
    float delai = 4.2;

    BOOST_CHECK(j->getNbVie() == 0);
    j->setNbVie(vie);
    BOOST_CHECK(j->getNbVie() == vie);

    BOOST_CHECK(j->getShield() == 0);
    j->setShield(shield);
    BOOST_CHECK(j->getShield() == shield);

    BOOST_CHECK(j->getDelai() <= Joueur::JOUEUR_BASE_DELAI);
    j->setDelai(delai);
    BOOST_CHECK(j->getDelai() >= delai);

    j->setNbVie(1);
    j->perdreVie();
    BOOST_CHECK(j->getNbVie() == 0 && j->getPointDeVie() == Joueur::JOUEUR_BASE_PV);
    j->perdreVie();
    BOOST_CHECK(j->getNbVie() == 0 && j->getPointDeVie() == Joueur::JOUEUR_BASE_PV);
    j->gagnerVie();
    BOOST_CHECK(j->getNbVie() == 1 && j->getPointDeVie() == Joueur::JOUEUR_BASE_PV);

    delete j;
}


BOOST_AUTO_TEST_CASE(EnnemiTest)
{
    Ennemi * e = new Ennemi();

    unsigned int id = 42;
    int domages = 666;
    float tir = 1.0;
    int val = 1664;

    BOOST_CHECK(e->getId() == 0);
    e->setId(id);
    BOOST_CHECK(e->getId() == id);

    BOOST_CHECK(e->getDommages() == 0);
    e->setDommages(domages);
    BOOST_CHECK(e->getDommages() == domages);

    BOOST_CHECK(e->getCadenceTir() <= 0);
    e->setCadenceTir(tir);
    BOOST_CHECK(e->getCadenceTir() >= 1.0);

    BOOST_CHECK(e->getValeur() == 0);
    e->setValeur(val);
    BOOST_CHECK(e->getValeur() == val);

    delete e;
}
