#include "fieldbouncer.h"

FieldBouncer::FieldBouncer()
{
  hit = FALSE;

  speed = 1;

  xdir = 2;
  ydir = -2;

  image.load(":/Images/bouncers.png");
  rect = image.rect();



}

FieldBouncer::~FieldBouncer() {
  std::cout << ("FieldBouncer deleted\n");
}


void FieldBouncer::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() <= 0) {
    xdir = speed;
  }

  if (rect.right() >=1000) {
    xdir = -(speed);
  }

  if (rect.top() <= 0) {
   ydir = speed;
  }
}

void FieldBouncer::resetState(int a, int b)
{
  rect.moveTo(a, b);
}

void FieldBouncer::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void FieldBouncer::moveTop(int top)
{
  rect.moveTop(top);
}

void FieldBouncer::moveLeft(int left)
{
  rect.moveLeft(left);
}

void FieldBouncer::moveRight(int right)
{
  rect.moveRight(right);
}

void FieldBouncer::setXDir(int x)
{
  xdir = x;
}

void FieldBouncer::setYDir(int y)
{
  ydir = y;
}

void FieldBouncer::setHit(bool Hit)
{
 hit = Hit;
}

void FieldBouncer::setSpeed(int Spd)
{
 speed = Spd;
}

bool FieldBouncer::getHit()
{
 return hit;
}

int FieldBouncer::getXDir()
{
  return xdir;
}

int FieldBouncer::getYDir()
{
  return ydir;
}

int FieldBouncer::getTop()
{
    return (rect.top());
}

int FieldBouncer::getSpeed()
{
 return speed;
}

QRect FieldBouncer::getRect()
{
  return rect;
}

QImage & FieldBouncer::getImage()
{
  return image;
}
