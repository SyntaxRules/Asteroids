/********************************************
 * This driver program is meant to exercise
 *   the bullet. The main goal is to get the
 *   Projectile class working (since projectile
 *   is pure virtual)
 *
 * Authors : Devyn Stott, Justin Ricks
 *******************************************/

#include "vector.h"
#include "bullet.h"
#include "uiInteract.h"
#include "uiDraw.h"

#define deg2rad(value) ((M_PI / 180) * (value))

using namespace std;

/*************************************
 * Take the user interface, when ever the user hits 
 * the space bar fire a bullet.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
   Bullet *pBullet = (Bullet *)p;   
   
   //if (pUI->isSpace())
   (*pBullet)++;
   
   pBullet->draw();
   //pBullet->advance();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * the bullet type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "bulletDriver");
   Bullet bullet;
   bullet.setDx(-5);
   bullet.setDy(5);
   ui.run(callBack, &bullet);

   return 0;
}
