/***********************************************************************************************
 * Project 4 :: Asteroids
 *      This class is designed to hold of of the objects and handle the game of asteroids.
 *      It should have a way to advance and display.
 * Authors:
 *      Justin Ricks and Devyn Stott
 ******************************************************************************************/

#include "vector.h"
#include "uiInteract.h"
#include "score.h"

#ifndef ENUM
#define ENUM
enum Type { BULLET, SHIP, ROCK };
#endif // ENUM

#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <list>

using namespace std;

// Forward declaration
class Projectile;

/**************************************************
 * The game class is mostly just a container for
 *    the items the game uses
 *************************************************/
class Asteroids
{
  public:
   Asteroids();
   void advance(const Interface * pUI);
   void draw();
   void addItem(Projectile * p);
   void addScore(int add) { score.addScore(add);};
  private:
   list<Projectile *> items;
   Score score;
};

class Projectile
{
  public:
   // Constructors
   Projectile(                ) : dead(false), v(    ) {};
   Projectile(Point & pt      ) : dead(false), v(pt  ) {};
   Projectile(float x, float y) : dead(false), v(x, y) {};

   // Methods
   bool isDead()     { return dead; };
   void kill ()       { dead = true; };
   void setDx(float dx) { v.setDx(dx); };
   void setDy(float dy) { v.setDy(dy); };
   Vector & getVector() { return v; };

   // Pure virtual functions
   virtual void operator ++ (int postfix) = 0;
   virtual void hit(Projectile * rhs, Asteroids * pGame);
   virtual void draw() = 0;
   virtual void event(const Interface * pUI, Asteroids * pGame) = 0;
   virtual Type getType() = 0;


  protected:
   bool dead;
   Vector v;
};


#endif //ASTEROIDS_H
