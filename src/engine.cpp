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

  player = new PlayerCar(0,QPoint(325,325));
  obstacles.push_back(new Obstacle); 
  (obstacles[0])->addVertex(100,100);
  (obstacles[0])->addVertex(200,100);
  (obstacles[0])->addVertex(200,200);
  (obstacles[0])->addVertex(100,200);

  obstacles.push_back(new Obstacle);
  (obstacles[1])->addVertex(0,0);
  (obstacles[1])->addVertex(0,2);
  (obstacles[1])->addVertex(650,2);
  (obstacles[1])->addVertex(650,0);

  obstacles.push_back(new Obstacle);
  (obstacles[2])->addVertex(2,2);
  (obstacles[2])->addVertex(2,650);
  (obstacles[2])->addVertex(0,650);
  (obstacles[2])->addVertex(0,2);

  obstacles.push_back(new Obstacle);
  (obstacles[3])->addVertex(0,650);
  (obstacles[3])->addVertex(650,650);
  (obstacles[3])->addVertex(650,648);
  (obstacles[3])->addVertex(0,648);

  obstacles.push_back(new Obstacle);
  (obstacles[4])->addVertex(650,650);
  (obstacles[4])->addVertex(650,0);
  (obstacles[4])->addVertex(648,0);
  (obstacles[4])->addVertex(648,650);

  obstacles.push_back(new Obstacle); 
  (obstacles[5])->addVertex(400,400);
  (obstacles[5])->addVertex(500,400);
  (obstacles[5])->addVertex(500,500);
  (obstacles[5])->addVertex(400,500);



}

void Engine::update(){

  intCar(player);
  checkCollisions();  

  this->parentWidget()->update();

}


void Engine::intCar(Car* car){
  
  double nVel = 0;
  if(car->getVelocity()>0){
    nVel = std::min(car->getVelocity()+car->getGear()
		    *car->getAcceleration()*dt/100 
		    - 0.4*dt/100,+0.5*car->getGear());
  } else {
    nVel = std::max(car->getVelocity()+car->getGear()
		    *car->getAcceleration()*dt/100 
		    + 0.4*dt/100,0. -car->getGear());
  }
  
  if(fabs(nVel) <= 0.041) { nVel = 0; } 

  car->setVelocity(nVel);

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

bool Engine::checkCollisions(){

  QPolygonF pl = player->getPolygon();
  bool colision = false;

  for(auto& ob : obstacles){
    colision =  !pl.intersected(ob->getPolygon()).empty() || colision;
  }
  
  if(colision){
    std::cout << "Colision!!" << std::endl;
    if(!player->ifInColision()){
      player->setColision();
      player->setVelocity(-player->getVelocity());
      player->setAcceleration(-player->getAcceleration());
    }
  } else {
    player->unsetColision();
    std::cout << "Empty!!" << std::endl;
  }
  
  

}
