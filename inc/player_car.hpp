#ifndef  _PLAYER_CAR_H_
#define  _PLAYER_CAR_H_
#include "car.hpp"

class PlayerCar : public Car {

public:

  PlayerCar();
  PlayerCar(double angle,QPointF pos, Color col = Car::Green);
  ~PlayerCar(){};

protected:
  virtual void draw(QPainter* painter);

};

#endif
