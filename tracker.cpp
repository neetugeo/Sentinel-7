#include "tracker.h"

Tracker::Tracker()
{
    hit = FALSE;

    speed = 2;

    xdir = 2;
    ydir = -3;

    image.load(":/Images/hunter.png");
    rect = image.rect();
}

Tracker::~Tracker()
{
}

void Tracker::resetState(int a, int b)
{
    rect.moveTo(a,b);
}

void Tracker::moveBottom(int bottom)
{
    rect.moveBottom(bottom);
}

void Tracker::moveTop(int top)
{
    rect.moveTop(top);
}

void Tracker::moveLeft(int left)
{
    rect.moveLeft(left);
}

void Tracker::moveRight(int right)
{
    rect.moveRight(right);
}

void Tracker::autoMove(int top, int right)
{
    rect.translate(xdir, ydir);

    if(top < rect.top() && rect.top() > 0)
        ydir = -speed;
    if(top > rect.top() && rect.bottom() < 600)
        ydir = speed;
    if(top == rect.top() && rect.right() < 1000 && rect.left() > 0)
        ydir = 0;
    if((right-10) < rect.right())
        xdir = -speed;
    if((right-10) > rect.right())
        xdir = speed;
    if (right == rect.right())
        xdir = 0;
    if (rect.top() == 0)
        ydir = speed;
}

void Tracker::setXDir(int x)
{
    xdir = x;
}

void Tracker::setYDir(int y)
{
    ydir = y;
}

void Tracker::setHit(bool Hit)
{
    hit = Hit;
}

void Tracker::setSpeed(int spd)
{
    speed = spd;
}

bool Tracker::getHit()
{
    return hit;
}

int Tracker::getXDir()
{
    return xdir;
}

int Tracker::getYDir()
{
    return ydir;
}

int Tracker::getSpeed()
{
    return speed;
}

int Tracker::getTop()
{
    return (rect.top());
}

QRect Tracker::getRect()
{
    return rect;
}

QImage & Tracker::getImage()
{
    return image;
}
