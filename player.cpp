#include "player.h"
#include <iostream>

Player::Player()
{
  image.load(":/Images/FirstShip.png");

  rect = image.rect();
  resetState();
}

Player::~Player()
{
 std::cout << ("Player deleted\n");
}

void Player::moveLeft(int left)
{
  if (rect.left() > 0)
    rect.moveTo(left, rect.top());
}

void Player::moveRight(int right)
{
  if (rect.right() < 1000)
    rect.moveTo(right, rect.top());
}

void Player::moveUp(int up)
{
    if (rect.top() > 300)
        rect.moveTo(rect.left(), up);
}

void Player::moveDown(int down)
{
    if (rect.bottom() < 600)
        rect.moveTo(rect.left(), down);
}

void Player::resetState()
{
  rect.moveTo(450, 500);
}

int Player::getTop()
{
    return (rect.top());
}

int Player::getRight()
{
    return (rect.right());
}

QRect Player::getRect()
{
  return rect;
}

QImage & Player::getImage()
{
  return image;
}
