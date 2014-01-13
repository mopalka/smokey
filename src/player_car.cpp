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

  QLinearGradient gradient(310, 60, 310, 10);
  
  if(getVelocity() < 0){
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
  } else {
    gradient.setColorAt(0, QColor::fromRgbF(0, 0, 1, 1));
  }
  gradient.setColorAt(1, QColor::fromRgbF(1, 0, 0, 1));
 
  QBrush brush(gradient);
 
  painter->setBrush(brush);
  painter->setPen(Qt::NoPen);
  painter->drawRect(QRect(310, 55+10, 10, - abs(55*getVelocity()/4.0)));
 
  painter->setRenderHint(QPainter::HighQualityAntialiasing);
  painter->translate(QPoint(330,10));
  painter->translate(QPoint(30,29));
  painter->rotate(getAngle());
  painter->translate(-QPoint(30,29));
  painter->drawPixmap(0,0,QPixmap(":/pic/wheel.png"));
  painter->restore();

}
