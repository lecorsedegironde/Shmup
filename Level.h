#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Ennemi.h"

class Level
{
private:
    float m_difficulte;
public:
    Level();
    Level(unsigned int difficulte);
    Level(const Level& l);
    virtual ~Level();

    float getDifficulte() const;
    void setDifficulte(const unsigned int &d);

    std::vector<Ennemi*> genLevel();
};

#endif // LEVEL_H
