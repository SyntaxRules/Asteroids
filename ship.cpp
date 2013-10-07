#include <cmath>
#include "ship.h"
#include "uiDraw.h"
#include "bullet.h"
#include "vector.h"

#define deg2rad(value) ((M_PI / 180) * (value))

using namespace std;

Ship::Ship()
{
   rotation = 0;
}

/************************************************
 * SHIP::DRAW
 ***********************************************/
void Ship :: draw()
{
   Point pt(v.getX(), v.getY());
   
   drawShip(pt, rotation);

   return;

}

/**********************************************************
 * SHIP::EVENT
 * INPUT:  Pointer to interface, pointer to game
 *   handles the user input and moves the ship or fires
 *   a bullet
 *********************************************************/
void Ship :: event(const Interface * pUI, Asteroids * pAstro)
{
   if (pUI->isRight())
      rotation -= 7;
   if (pUI->isLeft())
      rotation += 7;
   if (pUI->isUp())
   {
      v.addDx(-.2 * cos(deg2rad(rotation)));
      v.addDy(-.2 * sin(deg2rad(rotation)));
   }

   
   if (pUI->isSpace())
   {
      Bullet * p = new Bullet;

      // Set the position to be in front of the ship
      p->getVector().setX(v.getX() - (2 * cos(deg2rad(rotation))));
      p->getVector().setY(v.getY() - (2 * sin(deg2rad(rotation))));

      // Set the speed of the new bullet
      p->setDx(-5 * cos(deg2rad(rotation)) + v.getDx());
      p->setDy(-5 * sin(deg2rad(rotation)) + v.getDy());

      // Add the bullet to the game
      pAstro->addItem(p);
   }

   return;
}

