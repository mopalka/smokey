#include "car.hpp"
#include <QPainter>
#include <cstdlib>

const char*  Car::pngs[] = {":/pic/black-car.png",
			    ":/pic/blue-car.png",
			    ":/pic/green-car.png",
			    ":/pic/orange-car.png"};


Car::Car() :  angle(0), position(0,0), velocity(0,0) {

 
}


Car::Car(double ang, QPoint pos, QPoint vel) : 	angle(ang), 
						position(pos),
						velocity(vel) {


}

 
void Car::draw(QPainter* painter){
  
  painter->save();
  painter->translate(position+QPoint(14,30));
  painter->rotate(angle);

  painter->translate(-QPoint(14,30));
  painter->drawPixmap(0,0,QPixmap(Car::pngs[rand() % 4]));
  
  painter->restore();

}
