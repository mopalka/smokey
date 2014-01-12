#ifndef  _CAR_H_
#define  _CAR_H_
#include "gobject.hpp"
#include <QPointF>


class Car : public GObject {

  
  
public:

  typedef enum {Black = 0, Blue, Green, Orange} Color;

  Car();
  Car(double angle,QPointF pos, Color col = Car::Black);
  ~Car(){};
  virtual void draw(QPainter* painter);
  
  const char*  getPng(){
    return pngs[static_cast<int>(color)];
  }

  void modPosition(QPointF pos){
    position += pos;
  };

  void modAngle(double ang){
    angle += ang;
  };

  
  void setPosition(QPointF pos){
    position = pos;
  };

  QPointF getPosition(){
    return position;
  };

  void setVelocity(double vel){
    velocity = vel;
  };

  double getVelocity(){
    return velocity;
  };

  void setAngVelocity(double angV){
    angVelocity = angV;
  };

  double getAngVelocity(){
    return angVelocity;
  };


  void setAngle(double ang){
    angle = ang;
  };

  double getAngle(){
    return angle;
  };

  void setOrientation(double ori){
    orientation = ori;
  };

  double getOrientation(){
    return orientation;
  };
  
  
private:
  double orientation;
  double angle;
  double angVelocity;
  QPointF position;
  double velocity;
  Color color;
  const static char*  pngs[];
  
};

#endif
