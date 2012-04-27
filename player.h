#ifndef PLAYER_H
#define PLAYER_H

#include <QImage>
#include <QRect>

class Player
{

  public:
    Player();
    ~Player();

  public:
    void resetState();
    void moveLeft(int);
    void moveRight(int);
    void moveUp(int);
    void moveDown(int);

    int getTop();
    int getRight();

    QRect getRect();
    QImage & getImage();

  private:
    QImage image;
    QRect rect;

};

#endif
