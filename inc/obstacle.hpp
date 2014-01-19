#ifndef  _OBSTACLE_H_
#define  _OBSTACLE_H_
#include "gobject.hpp"
#include <QPolygon>
#include <QPoint>

class QPainter;

class Obstacle : public GObject {
 
public:
  Obstacle(){};
  ~Obstacle(){};
  
  void addVertex(double x,double y){
    vertices << QPointF(x,y);
  }

  QPolygonF getPolygon(){
    return vertices;
  }
  
protected:
  virtual void draw(QPainter* painter);  
  QPolygonF vertices;

};


#endif
