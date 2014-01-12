#include "engine.hpp"
#include "car.hpp"
#include <QPoint>
#include <cstdlib>
#include <QKeyEvent>     
#include <cmath>
#include <algorithm>    

Engine::Engine(QWidget* parent) : QWidget(parent) {

  dt = 10;
  setFocusPolicy(Qt::StrongFocus);
  timer.setInterval(dt);
  connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
  timer.start();

  player = new Car(0,QPoint(200,200));
  
}

void Engine::update(){
  
  //std::cout << "Timer is tic-tic-ticin!" << std::endl;
  
  intCar(player);

  this->parentWidget()->update();

}


void Engine::intCar(Car* car){
  
  QPointF dPos(-sin(car->getOrientation()*3.14/180)*car->getVelocity(),
	      cos(car->getOrientation()*3.14/180)*car->getVelocity());


  double nAng = 0;
  if(car->getAngVelocity()>0){
    nAng = std::min(car->getAngle()+car->getAngVelocity()*dt/50,+45.);
  } else {
    nAng = std::max(car->getAngle()+car->getAngVelocity()*dt/50,-45.);
  }
  
  car->setAngle(nAng);  
  std::cout << "angle: " << car->getAngle() << std::endl;
  car->setOrientation(fmod(car->getOrientation()
			   -tan((3.14/180)*car->getAngle())*car->getVelocity()*dt/5,360));

  car->setPosition(car->getPosition()+dPos);
  

}
