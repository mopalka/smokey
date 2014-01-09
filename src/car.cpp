#include "car.hpp"
#include <QPainter>

void Car::draw(QPainter* painter){
  
  painter->drawPixmap(10,10,QPixmap(":/pic/bear.png"));

}
