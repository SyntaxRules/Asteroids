/**********************************************************
 * bullet.cpp project4 Asteroids
 * Authors: Justin Ricks and Devyn Stott
 ***********************************************************/

#include "vector.h"
#include "bullet.h"
#include "uiDraw.h"

#include <iostream>

using namespace std;

Bullet :: Bullet() : Projectile()
{
   dead = false;
   life = 60;
}

void Bullet :: draw()
{
   Point point(v.getX(), v.getY());
   drawDot(point);
}

void Bullet :: operator ++ (int postfix)
{
   v++;

   if (life <= 0)
      dead = true;
   else
      life--;
}
