#ifndef ANDROMEDA_H
#define ANDROMEDA_H

#include <QRect>
#include <QImage>
#include <iostream>
#include "boss.h"

class Andromeda : public Boss
{
private:
    QImage image;
    QRect rect;


public:
    Andromeda(int spd, int heal, bool dft);
    Andromeda();
    ~Andromeda();

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

#endif // ANDROMEDA_H
