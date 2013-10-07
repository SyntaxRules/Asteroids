/****************************************************************************
 * rocks.cpp contains all of the member functions for LargeRock, MedRock and
 * SmallRock. They are so similar that it makes sense to put them in the same
 * place.
 * Authors: Justin Ricks and Devyn Stott
 ***************************************************************************/

#include "point.h"
#include "rock.h"
#include "uiDraw.h"

Point tempPoint(float x, float y)
{
   Point temp;
   temp.setX(x);
   temp.setY(y);
   return temp;
}

MedRock::MedRock()
{
   rotation = random(0, 360); // Random orientation
   size = 10;
   numSides = 7;
}

LargeRock::LargeRock()
{
   v.setX(POINT_MAX);
   v.setY(random(-POINT_MAX, POINT_MAX));
   v.setDx(random(-20, 20) / 10.0);
   v.setDy(random(-20, 20) / 10.0);
   rotation = random(0, 360); // Random orientation
   size = 20;
   numSides = 5;
}

SmallRock::SmallRock()
{
   rotation = random(0, 360);
   size = 5;
   numSides = 10;
}

void Rock :: draw()
{
   // We need to draw 5!! For screen wrapping
   // One where it is
   drawAsteroid(tempPoint(v.getX(), v.getY()), size, numSides, rotation);

   // One to the right
   drawAsteroid(tempPoint(v.getX() + 2*POINT_MAX, v.getY()), size, numSides, rotation);

   // One to the left
   drawAsteroid(tempPoint(v.getX() - 2*POINT_MAX, v.getY()), size, numSides, rotation);

   // One above it
   drawAsteroid(tempPoint(v.getX(), v.getY() + 2*POINT_MAX), size, numSides, rotation);

   // One below it
   drawAsteroid(tempPoint(v.getX(), v.getY() - 2*POINT_MAX), size, numSides, rotation);
}


void LargeRock :: hit(Projectile * rhs, Asteroids * pGame)
{
   //This is only called when min distance is confirmed
   float minD = 0;
   minD = minDistance(this->v, rhs->getVector());
   cerr << "MinD : LargeRock :  " << minD << endl;
   if (minD <= size)
   {
      kill();
      rhs->kill();

      pGame->addScore(100);
      
      MedRock * p1 = new MedRock;
      //set new velocities
      p1->getVector().setDy(this->v.getDy() + 1.0);
      p1->getVector().setDx(this->v.getDx());
      //set new starting point
      p1->getVector().setX(v.getX());
      p1->getVector().setY(v.getY());
      
      MedRock * p2 = new MedRock;
      p2->getVector().setDy(this->v.getDy() + -1.0);
      p2->getVector().setDx(v.getDx());
      p2->getVector().setX(v.getX());
      p2->getVector().setY(v.getY());
      
      SmallRock * p3 = new SmallRock;
      p3->getVector().setDx(this->v.getDx() + 2.0);
      p3->getVector().setDy(v.getDy());
      p3->getVector().setX(v.getX());
      p3->getVector().setY(v.getY());
      
      pGame->addItem(p1);
      pGame->addItem(p2);
      pGame->addItem(p3);
   }
}

void MedRock :: hit(Projectile * rhs, Asteroids * pGame)
{
   float minD = 0;
   minD = minDistance(this->v, rhs->getVector());
   if (minD <= size)
   {
      kill();
      rhs->kill();

      pGame->addScore(75);
      
      SmallRock * p1 = new SmallRock;
      p1->getVector().setDx(this->v.getDx() + 3.0);
      p1->getVector().setDy(v.getDy());
      p1->getVector().setX(v.getX());
      p1->getVector().setY(v.getY());

      SmallRock * p2 = new SmallRock;
      p2->getVector().setDx(this->v.getDx() - 3.0);
      p1->getVector().setDy(v.getDy());
      p2->getVector().setX(v.getX());
      p2->getVector().setY(v.getY());

      pGame->addItem(p1);
      pGame->addItem(p2);
   }
}
   

void SmallRock :: hit(Projectile * rhs, Asteroids * pGame)
{
   float minD = 0;
   minD = minDistance(this->v, rhs->getVector());
   if (minD <= size)
   {
      kill();
      rhs->kill();

      //spawn a new large on upon death
      LargeRock * p1 = new LargeRock;

      pGame->addItem(p1);
      
      pGame->addScore(50);
   }
}
