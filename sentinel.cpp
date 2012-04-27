#include "sentinel.h"
#include <iostream>
#include <QPainter>
#include <QApplication>

Sentinel::Sentinel(QWidget *parent)
    : QWidget(parent)
{
  x = 0;
  lives = 5;
  lives2 = 5; //ATM unnecessary.
  lives3 = 5;
  holdx = 0;
  MC = 0;
  M2C = 0;
  Invade1 = FALSE; //pass booleans. Two passes means you lose.
  Invade2 = FALSE;
  Death = FALSE;
  CityLost = FALSE; //bool for paint screen
  gameWon = FALSE; //bool for victory
  paused = FALSE;
  Respawn = FALSE;
  gameStarted = FALSE;
  E1C = FALSE;
  E2C = FALSE;
  Score = 100;
  Level1 = TRUE;
  Level2 = FALSE;
  Level3 = FALSE;

  for (int i = 0; i < 30; i++)
      ball[i] = new Ball();

  //setting new objects to the ball array

  for (int i = 0; i < 10; i++)
     {
      runner[i] = new Runner();
      runner[i]->resetState(i*100, 0);
    }

  //setting runnre objects to the runner array

  for(int i = 0; i < 30; i++)
  {tracker[i] = new Tracker();
      tracker[i]->resetState(50,60);}

  //setting trackers to tracker array.

  for (int i=0; i < lives; i++)
   {
      life[i] = new Life();
      life[i]->Reset(i*20, 0);
   }

  //setting lives.

  ball[MC]->resetState(700,50);
  ball[MC+1]->resetState(200,50);
  //setting all your ball objects to spawn locations
  ball[MC+1]->setSpeed(2);
  //setting the speed for moving ball objects
  player = new Player();
  altair = new Altair();
  altair->resetState();



  //Breaking bricks into three groups.
  //Now you can place them in different areas if need be.

  for (int i = 0; i < 5; i++)
  {bricks1[i] = new Brick(i*50 + 10, 250);}

  for (int i = 0; i < 5; i++)
  {bricks2[i] = new Brick(i*50 + 300, 250);}

  for (int i = 0; i < 5; i++)
  {bricks3[i] = new Brick(i*50 + 700, 250);}
}

Sentinel::~Sentinel() {
 for (int k=0; k<30; k++)
   delete ball[k];

 delete player;

 for (int i=0; i<5; i++) {
   delete bricks1[i];
 }

 for (int i=0; i<5; i++) {
   delete bricks2[i];
 }

 for (int i=0; i<5; i++) {
   delete bricks3[i];
 }
}

void Sentinel::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  painter.setPen(QPen(QColor(255,255,255)));
  painter.setBrush(QBrush(QColor(0,0,255)));


//when your player dies, this screen will appear
  if (Death) {
    QFont font("Courier", 15, QFont::Normal);
    QFontMetrics fm(font);
    int textWidth = fm.width("And his battered ship");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, -30, "And the battered ship");

    textWidth = fm.width("would forever drift");
    painter.drawText(-textWidth/2,-15,"would forever drift");

    textWidth = fm.width("the expanses of space");
    painter.drawText(-textWidth/2,0,"the expanses of space");

    textWidth = fm.width("taking with it");
    painter.drawText(-textWidth/2,15,"taking with it");

    textWidth = fm.width("a wandering soul.");
    painter.drawText(-textWidth/2,30,"a wandering soul.");
  }

 //if the city is invaded, this screen will appear
  else if(CityLost)
  {
   QFont font("Courier", 15, QFont::Normal);
   QFontMetrics fm(font);

   int textWidth = fm.width("But the Machina were too strong;");
   painter.setFont(font);
   int w = width();
   int h = height();

   painter.translate(QPoint(w/2 ,h/2));
   painter.drawText(-textWidth/2,-15,"But the Machina were too strong;");

   textWidth = fm.width("the pilot was overcome");
   painter.drawText(-textWidth/2,0,"the pilot was overcome");

   textWidth = fm.width("before reinforcements ever arrived.");
   painter.drawText(-textWidth/2,15,"before reinforcements ever arrived.");
  }

  //if you win, this screen will appear

  else if(gameWon) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Victory");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Victory");
  }

  else {

      //painter function to update image locations.

      painter.drawImage(player->getRect(),player->getImage());

      for(int i = 0; i < lives; i++)
      {
          if(!life[i]->lifeLost())
              painter.drawImage(life[i]->getRect(),life[i]->getImage());
      }

    if(!ball[MC]->getHit() && Level1 && !Level2 && !Level3)
      {painter.drawImage(ball[MC]->getRect(),ball[MC]->getImage());}

    if(!ball[MC+1]->getHit())
      {painter.drawImage(ball[MC+1]->getRect(),ball[MC+1]->getImage());}

    if(!tracker[M2C]->getHit() && Level1 && Level2 && !Level3)
      {painter.drawImage(tracker[M2C]->getRect(), tracker[M2C]->getImage());}

    for (int i = 0; i < 10; i++)
    {if (!runner[i]->getHit() && Level1 && Level2 && Level3)
            painter.drawImage(runner[i]->getRect(), runner[i]->getImage());
    }

    if(!altair->getDefeat())
    {painter.drawImage(altair->getRect(),altair->getImage());}

    if (!laser->getContact())
      painter.drawImage(laser->getRect(),laser->getImage());

    if (!enemylaser->getContact())
        painter.drawImage(enemylaser->getRect(),enemylaser->getImage());

    for (int i=0; i<5; i++) {
        if (!bricks1[i]->isDestroyed())
          painter.drawImage(bricks1[i]->getRect(), bricks1[i]->getImage());
    }

    for (int i=0; i<5; i++) {
        if (!bricks2[i]->isDestroyed())
          painter.drawImage(bricks2[i]->getRect(), bricks2[i]->getImage());
    }

    for (int i=0; i<5; i++) {
        if (!bricks3[i]->isDestroyed())
          painter.drawImage(bricks3[i]->getRect(), bricks3[i]->getImage());
    }

  }

}

void Sentinel::timerEvent(QTimerEvent *event)
{

    //clock functioning in the background, these objects will move as long as the clock cycle is on.
    //automove functions specified inside their respective classes.


    //Conditions for ball enemies. Only appear in level 1.
 if (!ball[MC]->getHit() && Level1 && !Level2 && !Level3)
     ball[MC]->autoMove();

 //Conditions for tracker enemies. Only appear in Level 2.
 if (!tracker[M2C]->getHit() && Level1 && Level2 && !Level3)
     tracker[M2C]->autoMove(player->getTop(), player->getRight());

 //The runner enemies only appear in level3.
 for (int i = 0; i < 10; i++)
 {
     if(!runner[i]->getHit() && Level1 && Level2 && Level3)
         runner[i]->autoMove();
 }

 //If the laser hasn't been hit, then keep moving.
 if (!laser->getContact())
   {
    laser->autoMove();
   }

 if (!altair->getDefeat())
   {
     altair->autoMove();
   }


 if (!enemylaser->getContact())
    {
     enemylaser->autoMove();
    }

 //Because balls spawn in twos, MC and MC+1 update in the RESPAWN function.
 if (!ball[MC+1]->getHit() && Level1 && !Level2 && !Level3)
  ball[MC+1]->autoMove();

  checkCollision();

  if (Respawn == TRUE)
  {

      if (MC < 30 && Level1 && !Level2 && !Level3)
        {MC = MC + 2; //Respawn in pairs, so update MC by 2
        ball[MC]->resetState(200, 50);
        ball[MC+1]->resetState(800, 50);
        ball[MC+1]->setSpeed(2);
        E1C = FALSE;
        E2C = FALSE;
        Respawn = FALSE;}

      if (M2C < 30 && Level1 && Level2 && !Level3)
        {
          M2C = M2C++; //Trackers use M2C to track index. Updates by one.
          if (M2C % 2 == 0) //These spawn in two locations so modulus regulates where they spawn.
           {
            tracker[M2C]->resetState(300, 30);
            Respawn = FALSE;
           }
          else
           {
              tracker[M2C]->resetState(700,30);
              Respawn = FALSE;
           }
        }
   }

  repaint();
}
//added variable int y to Sentinel.h
void Sentinel::keyPressEvent(QKeyEvent *event)
{
   switch (event->key())
   {
    case Qt::Key_Left:
       {
         int x = player->getRect().x();
        for (int i=1; i<=10; i++)
          player->moveLeft(x--);
       }
        break;
    case Qt::Key_Right:
        {
         int x = player->getRect().x();
         for (int i=1; i<=10; i++)
         player->moveRight(x++);
        }
        break;
    case Qt::Key_Up:
        {
          int y = player->getRect().y();
          for (int i=1; i<=10; i++)
              player->moveUp(y--);
        }
       break;
    case Qt::Key_Down:
       {
         int y = player->getRect().y();
         for (int i=1; i <= 10; i++)
             player->moveDown(y++);
       }
       break;
    case Qt::Key_P:
        {
          pauseGame();
        }
        break;
    case Qt::Key_Space:
        {
          startGame();
        }
        break;
    case Qt::Key_Escape:
        {
          close(); //qApp->exit(); didn't work, so use close(); instead.
        }
        break;
    case Qt::Key_W:
        {
         laser = new Laser(); //Makes your laser and fires it.
         laser->Reset(player->getRect().left()+27, player->getRect().top());
        }
        break;
    default:
       QWidget::keyPressEvent(event);
    }
}

void Sentinel::startGame()
{
  if (!gameStarted) {
    /*ball[MC]->resetState(700,50); //when the game starts, set MCs in place.
    ball[MC+1]->resetState(200,50);
    player->resetState(); //Set the player.
    altair->resetState(); //Set altair.

    //In general, this function sets things.

    for (int i=0; i<5; i++) {
      bricks1[i]->setDestroyed(FALSE);
    }

    for (int i=0; i<5; i++) {
      bricks2[i]->setDestroyed(FALSE);
    }


    for (int i=0; i<5; i++) {
      bricks3[i]->setDestroyed(FALSE);
    }

    Death = FALSE;
    gameWon = FALSE;*/
    gameStarted = TRUE;
    Level1 = TRUE;
    timerId = startTimer(10); //start this timer.
  }
}

void Sentinel::pauseGame()
{
  if (paused) {
    timerId = startTimer(10);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId);
   }
}

void Sentinel::PDeath()
{
  killTimer(timerId);
  Death = TRUE;
  gameStarted = FALSE;
}

void Sentinel::CDeath()
{
 killTimer(timerId);
 CityLost = TRUE;
 gameStarted = FALSE;
}

void Sentinel::victory()
{
  killTimer(timerId);
  //gameWon = TRUE;
  gameStarted = FALSE;
}

void Sentinel::checkCollision()
{
//ALTAIR
  if ((altair->getRect()).intersects(laser->getRect())) //if the boss collides with your laser...
    {
        laser->setContact(TRUE); //remove the laser image from play
        laser->Reset(0,0); //reset its position so you can freely delete it w/o repetition
        laser->~Laser(); //deallocate the laser
        cout << "Altair Hit!" << endl;
        altair->setDamage(); //altair takes damage

    }

  if ((altair->getRight()) == (player->getRight())) //if altair's right edge and the player's right edge overlap
    {
      enemylaser = new EnemyLaser(); //altair should fire a laser
      enemylaser->Reset((altair->getRight() - 40), (altair->getBottom())); //fire it from the relative middle
    }


  if (altair->getHealth() <= 0) //when altair's health depletes to zero
   {
      /*if(enemylaser != NULL) //if the enemy laser isn't currently empty.
      {
      enemylaser->setContact(TRUE); //take the EL image and hide it
      enemylaser->Reset(0,0); //reset it's position
      enemylaser->~EnemyLaser(); //deallocate
      }*/

      //if(Level1 && !Level2) //if you're currently in level1 and you defeat altair
        //secondSetUp(); //set up the second level stage
      //else if (Level1 && Level2 && !Level3) //if you're currently in level 2,
       //{thirdSetUp();} //set up the third level stage
      //else if (Level1 && Level2 && Level3) //if you're currently in level 3
      //{altair->setDefeat(TRUE); //take Altair out of play.
          //victory();} //you win!
   }

//BALL MC
  if ((ball[MC]->getRect()).intersects(laser->getRect()) && (ball[MC]->getTop()) != 0) //if ball intersects with laser
    {ball[MC]->setHit(TRUE); //take ball image out of play
     ball[MC]->resetState(0,0); //reset ball's position
     ball[MC]->~Ball(); //deallocate
     E1C = TRUE; //Enemy Cleared 1 is true (used for respawn)
     laser->~Laser(); //deallocate laser
     cout << "Collision!!" << endl;
  }
  if (ball[MC]->getRect().bottom() >= 600) //if ball ever hits 600
   {
     if (!Invade1) //if the first invasion didn't happen
         Invade1 = TRUE; //now it did

     else if (Invade1 == TRUE) //if the first invasion already happened
         Invade2 = TRUE; //you've now been invaded twice and it's game over.

    E1C = TRUE; //And your first enemy will clear to respawn.

    ball[MC]->setHit(TRUE);
    ball[MC]->resetState(0,0);
    ball[MC]->~Ball();
   }

//BALL MC2
  //Pretty much the same rules apply to Ball MC2 as it did to Ball MC1
  if ((laser->getRect()).intersects(ball[MC+1]->getRect()) && ball[MC+1]->getTop() != 0)
    {ball[MC+1]->setHit(TRUE);
     ball[MC+1]->resetState(0,0);
     ball[MC+1]->~Ball();
     laser->setContact(TRUE);
     E2C = TRUE;
     laser->Reset(0,600);
     laser->~Laser();
     cout << "Collision!" << endl;
  }

  if (ball[MC+1]->getRect().bottom() >= 600)
      {
        if (Invade1 != TRUE)
            Invade1 = TRUE;
        else if (Invade1 == TRUE)
            Invade2 = TRUE;

        E2C = TRUE;

        ball[MC+1]->setHit(TRUE);
        ball[MC+1]->resetState(0,0);
        ball[MC+1]->~Ball();
      }

//DESTROY BRICKS
  for (int i=0; i<5; i++)
  {
    if ((laser->getRect()).intersects(bricks1[i]->getRect())) //if the bricks and laser intersect
    {
     bricks1[i]->setDestroyed(TRUE); //take away the brick image
     bricks1[i]->~Brick(); //delete it
     laser->setContact(TRUE); //take laser out of play
     laser->Reset(0,0); //reset position
     laser->~Laser(); //deallocate laser
    }
  }
  for (int i=0; i<5; i++)
  {
    if ((laser->getRect()).intersects(bricks2[i]->getRect()))
    {
     bricks2[i]->setDestroyed(TRUE);
     bricks2[i]->~Brick();
     laser->setContact(TRUE);
     laser->Reset(0,0);
     laser->~Laser();
    }
  }
  for (int i=0; i<5; i++)
  {
    if ((laser->getRect()).intersects(bricks3[i]->getRect()))
    {
     bricks3[i]->setDestroyed(TRUE);
     bricks3[i]->~Brick();
     laser->setContact(TRUE);
     laser->Reset(0,0);
     laser->~Laser();
    }
  }


  //when enemy lasers hit bricks, the same thing happens as when a player hits them
  /*for (int i=0; i<5; i++)
  {
    if ((enemylaser->getRect()).intersects(bricks1[i]->getRect()))
    {
     bricks1[i]->setDestroyed(TRUE);
     delete bricks1[i];
     enemylaser->setContact(TRUE);
     enemylaser->Reset(0,0);
     enemylaser->~EnemyLaser();
    }
  }
  for (int i=0; i<5; i++)
  {
    if ((enemylaser->getRect()).intersects(bricks2[i]->getRect()))
    {
     bricks2[i]->setDestroyed(TRUE);
     delete bricks2[i];
     enemylaser->setContact(TRUE);
     enemylaser->Reset(0,0);
     enemylaser->~EnemyLaser();
    }
  }
  for (int i=0; i<5; i++)
  {
    if ((enemylaser->getRect()).intersects(bricks3[i]->getRect()))
    {
     bricks3[i]->setDestroyed(TRUE);
     delete bricks3[i];
     enemylaser->setContact(TRUE);
     enemylaser->Reset(0,0);
     enemylaser->~EnemyLaser();
    }
  }*/


//and again, this is just a repeat of the first two.
  for (int i=0; i<5; i++) {
         if ((ball[MC]->getRect()).intersects(bricks1[i]->getRect()))
       {
        bricks1[i]->setDestroyed(TRUE);
        bricks1[i]->~Brick();

        if (ball[MC]->getYDir() == -(ball[MC]->getSpeed()))
            ball[MC]->setYDir((ball[MC]->getSpeed()));
        if (ball[MC]->getYDir() == (ball[MC]->getSpeed()))
            ball[MC]->setYDir(-(ball[MC]->getSpeed()));
       }
     }
     for (int i=0; i<5; i++) {
         if ((ball[MC]->getRect()).intersects(bricks2[i]->getRect()))
       {
        bricks2[i]->setDestroyed(TRUE);
        bricks2[i]->~Brick();

        if (ball[MC]->getYDir() == -(ball[MC]->getSpeed()))
            ball[MC]->setYDir(ball[MC]->getSpeed());
        if (ball[MC]->getYDir() == ball[MC]->getSpeed())
            ball[MC]->setYDir(-(ball[MC]->getSpeed()));
       }
     }
     for (int i=0; i<5; i++) {
         if ((ball[MC]->getRect()).intersects(bricks3[i]->getRect()))
       {
        bricks3[i]->setDestroyed(TRUE);
        bricks3[i]->~Brick();

        if (ball[MC]->getYDir() == -(ball[MC]->getSpeed()))
            ball[MC]->setYDir((ball[MC]->getSpeed()));
        if (ball[MC]->getYDir() == (ball[MC]->getSpeed()))
            ball[MC]->setYDir(-(ball[MC]->getSpeed()));
       }
     }

     for (int i=0; i<5; i++) {
         if ((ball[MC+1]->getRect()).intersects(bricks1[i]->getRect()))
       {
        bricks1[i]->setDestroyed(TRUE);
        bricks1[i]->~Brick();

        if (ball[MC+1]->getYDir() == -(ball[MC+1]->getSpeed()))
            ball[MC+1]->setYDir((ball[MC+1]->getSpeed()));
        if (ball[MC+1]->getYDir() == (ball[MC+1]->getSpeed()))
            ball[MC+1]->setYDir(-(ball[MC+1]->getSpeed()));
       }
     }

     for (int i=0; i<5; i++) {
         if ((ball[MC+1]->getRect()).intersects(bricks2[i]->getRect()))
       {
        bricks2[i]->setDestroyed(TRUE);
        bricks2[i]->~Brick();

        if (ball[MC+1]->getYDir() == -(ball[MC+1]->getSpeed()))
            ball[MC+1]->setYDir((ball[MC+1]->getSpeed()));
        if (ball[MC+1]->getYDir() == (ball[MC+1]->getSpeed()))
            ball[MC+1]->setYDir(-(ball[MC+1]->getSpeed()));
       }
     }

     /*for (int i=0; i<5; i++) {
         if ((ball[MC+1]->getRect()).intersects(bricks3[i]->getRect()))
       {
        bricks3[i]->setDestroyed(TRUE);
        bricks3[i]->~Brick();

        if (ball[MC+1]->getYDir() == -(ball[MC+1]->getSpeed()))
            ball[MC+1]->setYDir((ball[MC+1]->getSpeed()));
        if (ball[MC+1]->getYDir() == (ball[MC+1]->getSpeed()))
            ball[MC+1]->setYDir(-(ball[MC+1]->getSpeed()));
       }
     }
//TRACKER
     if ((laser->getRect()).intersects(tracker[M2C]->getRect()) && tracker[M2C]->getTop() != 0)
         {tracker[M2C]->setHit(TRUE);
          tracker[M2C]->resetState(100,100);
          delete tracker[M2C];
          Respawn = TRUE;
     }

 //RUNNER
     for(int i = 0; i < 10; i++)
     {
         if((runner[i]->getRect()).intersects(player->getRect()))
            {lives--; //player loses a life when a runner hits them. But you can't kill a runner...
             runner[i]->resetState(i*100, 0); //When a player gets hit, the runner gets offset.
             //that's helpful during the last level.
         }

     }*/

//CONDITIONS

     //these projectile conditions take into account when a laser leaves the frame. It deallocates the object.
  /*if (laser->getRect().bottom() <= 0)
    {
      laser->setContact(TRUE);
      laser->Reset(0,0);
      laser->~Laser();
    }*/

  /*if (enemylaser->getRect().bottom() >= 600)
   {
      enemylaser->setContact(TRUE);
      enemylaser->Reset(0,0);
      enemylaser->~EnemyLaser();
   }

  if((enemylaser->getRect()).intersects(player->getRect()))
    {
      enemylaser->setContact(TRUE);
      enemylaser->Reset(0,0);
      enemylaser->~EnemyLaser();
      lives--;
      lives--;
    }*/

  //MC CONDITIONS
  if ((ball[MC]->getRect()).intersects(player->getRect()))
    {
      ball[MC]->setHit(TRUE);
      ball[MC]->resetState(0, 50);
      ball[MC]->~Ball();
      lives--;
      cout << lives;
      E1C = TRUE; //hitting an enemy adds to the respawn counter
    }

  if ((ball[MC+1]->getRect()).intersects(player->getRect()))
    {
      ball[MC+1]->setHit(TRUE);
      ball[MC+1]->resetState(0, 50);
      ball[MC+1]->~Ball();
      lives--;
      cout << lives;
      E2C = TRUE;
    }

  if ((tracker[M2C]->getRect()).intersects(player->getRect()))
    {

      tracker[M2C]->setHit(TRUE);
      tracker[M2C]->resetState(0, 50);
      tracker[M2C]->~Tracker();
      lives--;
      cout << lives;
      Respawn = TRUE;
    }

  if (lives <= 0)
    {
      PDeath();
    }

  //if (lives2 <= 0)
  //{
    //  PDeath();
  //}

  //if (lives3 <= 0)
  //{
   //   PDeath();
  //}

  /*if (Invade1 == TRUE && Invade2 == TRUE)
      {CDeath();} //if two invasions happen, you lose your hometown.

  else if (E1C == TRUE && E2C == TRUE)
    {Respawn = TRUE;} //if you kill two enemies, two more will appear.*/
}

void Sentinel::startLevel2()
{
    Level2 = TRUE; //change the level indicator

    //for(int i=0; i < lives2; i++)
     //{
      //  life[i]->setLost(FALSE);
     //}

    field2(); //setup the environment for field2

}

void Sentinel::field2()
{
    //for (int k=0; k<30; k++)
     //{
       // if (!ball[k]->getHit())
         //{ball[k]->setHit(TRUE);
         //ball[k]->resetState(100,100);
         //ball[k]->~Ball();} //get rid of all ball objects
     //}

    //altair->resetState(1000,500);
    //altair->~Altair(); //

}

void Sentinel::secondSetUp()
{
    for (int i = 0; i < 30; i++)
    {if (ball[i] != NULL)
        {   ball[i]->setHit(TRUE); //get rid of ball objects
            //ball[i]->resetState(0,0);
            //ball[i]->~Ball();
        }
    }

    Invade1 = FALSE;
    Invade2 = FALSE;
    Death = FALSE;
    CityLost = FALSE;
    gameWon = FALSE;
    paused = FALSE;
    Respawn = FALSE;
    E1C = FALSE;
    E2C = FALSE;
    Level2 = TRUE; //you're in the second level
    lives = 5; //reset your lives c:

    altair->setHealth(250);
    altair->setSpeed(7);
    altair->resetState(500,50);


}

void Sentinel::thirdSetUp() //Same idea as the second but this time you get rid of tracker
{
    for (int i = 0; i < 30; i++)
    {if (tracker[i] != NULL)
        {   tracker[i]->setHit(TRUE);}
    }

    Invade1 = FALSE;
    Invade2 = FALSE;
    Death = FALSE;
    CityLost = FALSE;
    gameWon = FALSE;
    paused = FALSE;
    Respawn = FALSE;
    E1C = FALSE;
    E2C = FALSE;
    Level3 = TRUE; //you're now in level3
    lives = 5;


    altair->setHealth(300);
    altair->setSpeed(10); //change the speed of the object
    altair->resetState(500,50);
}

