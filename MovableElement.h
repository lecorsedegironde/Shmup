#ifndef MOVABLE_ELEMENT_H
#define MOVABLE_ELEMENT_H


class MovableElement
{

protected:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    int m_dx;
    int m_dy;
    bool m_etat;

public:

    MovableElement();
    MovableElement(int x, int y, int w, int h, int dx, int dy);
    virtual ~MovableElement();

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

    virtual void detruire() {}  //Pour certains types -> Produire une explosion
    virtual bool testCollision(MovableElement * m);
};



#endif // MOVABLE_ELEMENT_H
