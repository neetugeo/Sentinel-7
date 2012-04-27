#include "altair.h"
using namespace std;

Altair::Altair(int spd, int heal, bool dft):Boss(spd, heal, dft)
{
    setSpeed(spd);
    setHealth(heal);
    setDefeat(dft);
    image.load(":/Images/truealtair.png");
    rect = image.rect();
    BossHit = FALSE;
    xdir = -speed;
}

Altair::Altair():Boss()
{
    speed = 5;
    health = 150;
    setDefeat(FALSE);
    image.load(":/Images/truealtair.png");
    rect = image.rect();
    BossHit = FALSE;
    xdir = -speed;
}

Altair::~Altair()
{}

void Altair::resetState()
{
    rect.moveTo(QPoint(500,50));
}

void Altair::resetState(int a, int b)
{
    rect.moveTo(a,b);
}

void Altair::autoMove()
{
    rect.translate(xdir,0);
    if (rect.right() >= 1000)
        xdir = -speed;
    if (rect.left() <= 0)
        xdir = speed;
}

void Altair::moveRight()
{

}

void Altair::moveLeft()
{

}

void Altair::moveTop()
{

}

void Altair::moveBottom()
{

}

void Altair::setDamage()
{
    int heal = getHealth();
    setHealth(heal-50);
    BossHit = FALSE;
    cout << getHealth() << endl;
}

int Altair::getRight()
{
    return (rect.right());
}

int Altair::getBottom()
{
    return (rect.bottom());
}

QRect Altair::getRect()
{
    return rect;
}

QImage & Altair::getImage()
{
    return image;
}
