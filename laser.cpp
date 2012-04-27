#include "laser.h"

Laser::Laser()
{
 xdir = 0;
 ydir = -10;
 contact = FALSE;

 image.load(":/Images/laser.png");
 rect = image.rect();
 rect.moveTo(0,0);
}

Laser::~Laser()
{};

void Laser::Reset(int X, int Y)
{
  rect.moveTo(X,Y);
}

void Laser::autoMove()
{
  rect.translate(xdir, ydir);
}

void Laser::setContact(bool Hit)
{
 contact = Hit;
}

bool Laser::getContact()
{
 return contact;
}

QRect Laser::getRect()
{
 return rect;
}

QImage& Laser::getImage()
{
 return image;
}
