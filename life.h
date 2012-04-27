#ifndef LIVES_H
#define LIVES_H

#include <QRect>
#include <QImage>

class Life
{
public:
    Life(int, int);
    Life();
    ~Life();

    bool lifeLost();

    void Reset(int, int);
    void setLost(bool);

    QRect getRect();
    QImage & getImage();

private:
    bool lost;

    QRect rect;
    QImage image;
};

#endif // LIVES_H
