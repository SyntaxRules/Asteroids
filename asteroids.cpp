/**********************************************************************
 * Project 4 :: Asteroids
 *      This file conatinas asteroids Member functions and ??Main??
 * Authors:
 *      Devyn Stott
 ********************************************************************/

#include "asteroids.h"
#include "bullet.h"

using namespace std;

/********************************************************************
 * ASTEROIDS::DRAW
 *    loops through every item in the list and tells it to draw itself
 *******************************************************************/
void Asteroids :: draw()
{
   // Loop through every item
   for (list<Projectile *>::iterator it = items.begin();
        it != items.end(); ++it)
      (*it)->draw();
   score.draw();
}

/********************************************************************
 * ASTEROIDS::ADVANCE
 *    loops through every item in the list and tells it to advance itself
 *******************************************************************/
void Asteroids :: advance(const Interface * pUI)
{
   // Loop through every item
   for (list<Projectile *>::iterator it = items.begin();
        it != items.end(); ++it)
   {
      // Check for collisions
      for (list<Projectile *>::iterator iter = items.begin();
           iter != items.end(); ++iter)
      {
         if ((*it)->getType() != (*iter)->getType())
            (*it)->hit(*iter, this);
      }
      
      // Advance the object
      (*it)->operator++(1);
      (*it)->event(pUI, this);
      
      // If it's dead, bury it
      if ((*it)->isDead())
      {
         // Erase the pointer from the list
         items.erase(it);
         // Free the memory
         delete (*it);
         // Decrement the iterator so that it does not
         //   advance this iteration
         --it;
      }   
   }
}

/********************************************************************
 * ASTEROIDS::ADDITEM
 *    adds a new projectile to the list
 *******************************************************************/
void Asteroids :: addItem(Projectile * p)
{
   // Add to the list
   items.push_back(p);
}

Asteroids::Asteroids() {};

void Projectile :: hit(Projectile * rhs, Asteroids * pGame)
{
   //float minD = 0;
   //minD = minDistance(v, rhs->v);      
}

