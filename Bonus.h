#ifndef BONUS_H
#define BONUS_H

#include "MovableElement.h"


class Bonus : public MovableElement
{
protected:
public:
    Bonus();
    Bonus(int x, int y, int w, int h, int dx, int dy);
    virtual ~Bonus();
};

#endif // BONUS_H
