#ifndef LASER_H
#define LASER_H

#include <QImage>
#include <QRect>

class Laser
{
public:
    Laser();
    ~Laser();

public:
    void autoMove();
    void Reset(int, int);
    void setXDir(int);
    void setYDir(int);
    void setContact(bool);

    bool getContact();
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

private:
    int xdir;
    int ydir;
    bool contact;
    QRect rect;
    QImage image;
};

#endif // LASER_H
