#ifndef  _CAR_H_
#define  _CAR_H_
#include "gobject.hpp"

class Car : public GObject {

public:
  Car(){};
  ~Car(){};
  virtual void draw(QPainter* painter);
  
};

#endif
