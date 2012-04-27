#ifndef ALTAIR_H
#define ALTAIR_H

#include "boss.h"
#include <QImage>
#include <QRect>
#include <iostream>

class Altair : public Boss
{
private:
    QImage  image;
    QRect rect;


public:
    Altair(int spd, int heal, bool dft);
    Altair();
    ~Altair();

    virtual void resetState();
    virtual void autoMove();
    virtual void moveRight();
    virtual void moveLeft();
    virtual void moveTop();
    virtual void moveBottom();

    void setDamage();
    void resetState(int, int);
    void autoFire(int, int);

    int getRight();
    int getBottom();

    bool BossHit;

    QImage & getImage();
    QRect getRect();
};

#endif // ALTAIR_H
