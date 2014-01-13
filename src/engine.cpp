#include "engine.hpp"
#include "player_car.hpp"
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

  player = new PlayerCar(0,QPoint(200,200));
  
}

void Engine::update(){
  
  //std::cout << "Timer is tic-tic-ticin!" << std::endl;
  
  intCar(player);

  this->parentWidget()->update();

}


void Engine::intCar(Car* car){
  
  double nVel = 0;
  if(car->getVelocity()>0){
    nVel = std::min(car->getVelocity()+car->getAcceleration()*dt/100 
		    - 0.4*dt/100,+4.);
  } else {
    nVel = std::max(car->getVelocity()+car->getAcceleration()*dt/100
		    + 0.4*dt/100,-4.);
  }
  
  if(fabs(nVel) <= 0.041) { nVel = 0; } 

  car->setVelocity(nVel);
  std::cout << "vel: " << car->getVelocity() << std::endl;

  QPointF dPos(-sin(car->getOrientation()*3.14/180)*car->getVelocity(),
	      cos(car->getOrientation()*3.14/180)*car->getVelocity());

  double nAng = 0;
  if(car->getAngVelocity()>0){
    nAng = std::min(car->getAngle()+car->getAngVelocity()*dt/30,+45.);
  } else {
    nAng = std::max(car->getAngle()+car->getAngVelocity()*dt/30,-45.);
  }
  
  car->setAngle(nAng);  
  
  car->setOrientation(fmod(car->getOrientation()
			   -tan((3.14/180)*car->getAngle())
			   *car->getVelocity()*dt/10,360));

  car->setPosition(car->getPosition()+dPos);

}
