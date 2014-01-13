#include "player_car.hpp"
#include <QPainter>

PlayerCar::PlayerCar() :  Car() {
  
  color = Car::Green;
  
}


PlayerCar::PlayerCar(double ori, QPointF pos,  Color col) : 
  Car(ori,pos,col) {  
  
}


void PlayerCar::draw(QPainter* painter){
  

  Car::draw(painter);

  painter->save();
  painter->setRenderHint(QPainter::HighQualityAntialiasing);
  painter->translate(QPoint(330,10));
  painter->translate(QPoint(30,29));
  painter->rotate(getAngle());
  painter->translate(-QPoint(30,29));
  painter->drawPixmap(0,0,QPixmap(":/pic/wheel.png"));
  painter->restore();

}
