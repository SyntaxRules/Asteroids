/********************************************
 * This driver program is meant to exercise
 *   the bullet. The main goal is to get the
 *   Projectile class working (since projectile
 *   is pure virtual)
 *
 * Authors : Devyn Stott, Justin Ricks
 *******************************************/

#include "asteroids.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "rock.h"
#include "ship.h"

#include <iostream>

#define deg2rad(value) ((M_PI / 180) * (value))

using namespace std;

/*************************************
 * Take the user interface, when ever the user hits 
 * the space bar fire a bullet.
 **************************************/
void callBack(const Interface * pUI, void * p)
{
   Asteroids * pAstro = (Asteroids *)p;

   pAstro->advance(pUI);
   
   pAstro->draw();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * the bullet type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "Game Driver");

   Asteroids astro;

   LargeRock * p1 = new LargeRock;
   LargeRock * p2 = new LargeRock;
   Ship      * ps = new Ship;
   LargeRock * p3 = new LargeRock;

   astro.addItem(p1);
   astro.addItem(p2);
   astro.addItem(ps);
   astro.addItem(p3);
   
   ui.run(callBack, &astro);

   return 0;
}
