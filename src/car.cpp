#include "car.hpp"
#include <QPainter>
#include <cstdlib>

const char*  Car::pngs[] = {":/pic/black-car.png",
			    ":/pic/blue-car.png",
			    ":/pic/green-car.png",
			    ":/pic/orange-car.png"};


Car::Car() :  orientation(0), angle(0), position(0,0), velocity(0) {

  color = static_cast<Color>(rand() % 4 );
 
}


Car::Car(double ori, QPointF pos,  Color col) : 	orientation(ori),
						angle(0),
						position(pos),
						velocity(0),
						color(col) {
  
  
						}

 
void Car::draw(QPainter* painter){
  
  painter->save();
  painter->setRenderHint(QPainter::HighQualityAntialiasing);
  painter->translate(position+QPoint(14,30));
  painter->rotate(orientation);

  painter->translate(-QPoint(14,30));
  painter->drawPixmap(0,0,QPixmap(getPng()));
  
  painter->restore();

}
