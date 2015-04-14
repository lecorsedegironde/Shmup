#ifndef MOVABLE_ELEMENT_H
#define MOVABLE_ELEMENT_H


class MovableElement
{
    public:
        MovableElement();
        MovableElement();
        virtual ~MovableElement();
        virtual bool isAlive();
        virtual detruire();
    protected:
        int m_x;
        int m_y;
        int m_w;
        int m_h;
        int m_dx;
        int m_dy;
        bool m_etat;
};

#endif // MOVABLE_ELEMENT_H
