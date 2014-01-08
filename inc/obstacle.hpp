#ifndef  _OBSTACLE_H_
#define  _OBSTACLE_H_
#include "gobject.hpp"

class Obstacle : public GObject {
 
public:
  Obstacle();
  ~Obstacle();

protected:
  virtual void draw();  

};


#endif
