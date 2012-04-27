//Images for this game have been found online. I own none of these pictures and use them for educational purposes only.
//pictures can be found on these websites:
//http://fractalsoftworks.com/2011/12/12/the-armada/
//http://www.pixeljoint.com/pixelart/48543.htm
//http://www.oocities.org/mewthree29/cast_page.html
//http://www.manitobamuseum.ca/main/planetarium-intro/say-it-with-a-star/

#include "sentinel.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPalette>

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 1000;
  int HEIGHT = 600;

  QDesktopWidget *desktop = QApplication::desktop();
  QPalette pic;
  QPixmap pixmap(":/Images/Stars.jpg");

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);

  pic.setBrush(QPalette::Background, pixmap);
  widget.setPalette(pic);


}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Sentinel window;

  window.setWindowTitle("Sentinel 7");
  window.show();
  center(window);

  return app.exec();
}
