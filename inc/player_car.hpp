#ifndef  _PLAYER_CAR_H_
#define  _PLAYER_CAR_H_
#include "car.hpp"

class PlayerCar : public Car {

public:
  PlayerCar();
  ~PlayerCar();

protected:
  virtual void draw();

};

#endif
