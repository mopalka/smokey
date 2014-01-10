#ifndef  _CAR_H_
#define  _CAR_H_
#include "gobject.hpp"
#include <QPoint>


class Car : public GObject {

public:
  Car();
  Car(double angle,QPoint pos, QPoint vel);
  ~Car(){};
  virtual void draw(QPainter* painter);

private:
  double angle;
  QPoint position;
  QPoint velocity;

  const static char*  pngs[];
  
};

#endif
