#ifndef  _CAR_H_
#define  _CAR_H_
#include "gobject.hpp"

class Car : public GObject {

public:
  Car();
  ~Car();

protected:
  virtual void draw();

};

#endif