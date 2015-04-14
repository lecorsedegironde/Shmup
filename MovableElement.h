#ifndef MOVABLE_ELEMENT_H
#define MOVABLE_ELEMENT_H


class MovableElement
{
    public:
        MovableElement();
        MovableElement(int x, int y, int w, int h, int dx, int dy);
        int getX() const;
        int getY() const;
        int getW() const;
        int getH() const;
        int getDx() const;
        int getDy() const;
        bool getEtat() const;

        void setX(const int &x);
        void setY(const int &y);
        void setW(const int &w);
        void setH(const int &h);
        void setDx(const int &dx);
        void setDy(const int &dy);
        void setEtat(const bool &etat);

        virtual ~MovableElement();
        virtual void detruire(){}

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
