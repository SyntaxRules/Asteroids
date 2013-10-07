/****************************************
 * UI TEST
 * Just a simple program to test the user
 * interface consisting of uiDraw and uiInteract
 ***************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ship.h"
using namespace std;

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
   Ship *pShip = (Ship *)p;

   // Increment
   (*pShip)++;
   
   // Handle movement
   pShip->event(pUI);

   // Draw the ship
   pShip->draw();

}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my ball type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "SHIP TEST!");
   Ship ship;
   ui.run(callBack, &ship);

   return 0;
}
