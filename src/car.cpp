#include "car.hpp"
#include <QPainter>
#include <cstdlib>

const char*  Car::pngs[] = {":/pic/black-car.png",
			    ":/pic/blue-car.png",
			    ":/pic/green-car.png",
			    ":/pic/orange-car.png"};


Car::Car() :  in_colision(false),
	      gear(1), acceleration(0), orientation(0), angle(0), 
	      angVelocity(0), position(0,0), velocity(0) {
  
  color = static_cast<Color>(rand() % 4 );
 
}


Car::Car(double ori, QPointF pos,  Color col) : 
  in_colision(false),
  gear(1), acceleration(0),   orientation(ori),   angle(0.),
  angVelocity(0),   position(pos),  velocity(0.),
  color(col) {
  
  }

 
void Car::draw(QPainter* painter){
  
  painter->save();
  painter->setRenderHint(QPainter::HighQualityAntialiasing);
  painter->translate(position+QPoint(14,30));
  painter->rotate(orientation);
  painter->translate(-QPoint(14,30));

  painter->translate(QPoint(0,10));
  painter->translate(QPoint(1.5,5.5)); 
  painter->rotate(angle*0.7);
  painter->translate(-QPoint(1.5,5.5)); 

  painter->drawPixmap(0,0,QPixmap(":/pic/tire.png"));

  painter->restore();

  // second wheel
  painter->save();
  painter->setRenderHint(QPainter::HighQualityAntialiasing);
  painter->translate(position+QPoint(14,30));
  painter->rotate(orientation);
  painter->translate(-QPoint(14,30));

  painter->translate(QPoint(25,10));
  painter->translate(QPoint(1.5,5.5)); 
  painter->rotate(angle*0.7);
  painter->translate(-QPoint(1.5,5.5)); 

  painter->drawPixmap(0,0,QPixmap(":/pic/tire.png"));
  painter->restore();

  
  // The car
  painter->save();
  painter->setRenderHint(QPainter::HighQualityAntialiasing);
  painter->translate(position+QPoint(14,30));
  painter->rotate(orientation);

  painter->translate(-QPoint(14,30));
  painter->drawPixmap(0,0,QPixmap(getPng()));
 
  painter->restore();

  
  painter->drawPolygon(getPolygon());


}



QPolygonF Car::getPolygon(){
  
  QPolygonF carPol;
  QPointF pos = getPosition();
  carPol << pos << pos+QPointF(+28,0) <<
    pos+QPointF(+28,+60) << pos+QPointF(0,+60);
  
  QTransform trs = QTransform().translate(pos.x()+14,pos.y()+30).
    rotate(getOrientation()).translate(-pos.x()-14,-pos.y()-30);
  return trs.map(carPol);
  
}
