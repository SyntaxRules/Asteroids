/********************************************
 * This driver program is meant to exercise
 *   the bullet. The main goal is to get the
 *   Projectile class working (since projectile
 *   is pure virtual)
 *
 * Authors : Devyn Stott, Justin Ricks
 *******************************************/

#include "vector.h"
#include "rock.h"
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
   LargeRock *pRock = (LargeRock *)p;   
   
   (*pRock)++;
   
   pRock->draw();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * the bullet type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "Rock Driver");
   LargeRock rock;
   ui.run(callBack, &rock);

   return 0;
}
