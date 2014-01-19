#include "player_car.hpp"
#include <QPainter>
#include <QFont>
#include <string>

PlayerCar::PlayerCar() :  Car() {
  
  color = Car::Green;
  
}


PlayerCar::PlayerCar(double ori, QPointF pos,  Color col) : 
  Car(ori,pos,col) {  
  
}


void PlayerCar::draw(QPainter* painter){
  

  Car::draw(painter);

  painter->save();

  QLinearGradient gradient(550, 60, 550, 10);
  
  if(getVelocity() < 0){
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
  } else {
    gradient.setColorAt(0, QColor::fromRgbF(0, 0, 1, 1));
  }
  gradient.setColorAt(1, QColor::fromRgbF(1, 0, 0, 1));
 
  QBrush brush(gradient);
 
  painter->setBrush(brush);
  painter->setPen(Qt::NoPen);
  double dim = getVelocity()<0? getVelocity() : 2*getVelocity();
  painter->drawRect(QRect(550, 55+10, 10, - abs(55*dim/4.0)));
  

  painter->setPen(Qt::red);
  std::string gr_no = std::to_string(getGear());
  painter->drawText(QPoint(562,76-getGear()*14),gr_no.c_str());

  painter->setRenderHint(QPainter::HighQualityAntialiasing);
  painter->translate(QPoint(580,10));
  painter->translate(QPoint(30,29));
  painter->rotate(getAngle());
  painter->translate(-QPoint(30,29));
  painter->drawPixmap(0,0,QPixmap(":/pic/wheel.png"));
  painter->restore();

}
