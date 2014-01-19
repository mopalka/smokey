#include "obstacle.hpp"
#include <QPainter>



void Obstacle::draw(QPainter* painter){
  painter->save();
  QBrush brush(Qt::red,Qt::SolidPattern);
  QPen pen(Qt::green);
  painter->setBrush(brush);
  painter->setPen(pen);
  painter->drawPolygon(vertices);
  painter->restore();
}
