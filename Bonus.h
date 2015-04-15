#ifndef BONUS_H
#define BONUS_H

#include "MovableElement.h"


class Bonus : public MovableElement
{
protected:
    unsigned int m_id;
public:
    Bonus();
    Bonus(int x, int y, int w, int h, int dx, int dy, unsigned int id);
    virtual ~Bonus();

    unsigned int getId() const;
    void setId(const unsigned int &id);
};

#endif // BONUS_H
