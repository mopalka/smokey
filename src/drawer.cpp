#include "drawer.hpp"
#include <QPainter>
#include "gobject.hpp"
#include "car.hpp"

Drawer::Drawer(QWidget* parent) : QWidget(parent) {

  setPalette(QPalette(QColor(200,200,200)));
  setAutoFillBackground(true);
  setFixedHeight(400);
  setFixedWidth(400);

}


Drawer::~Drawer(){

}


void Drawer::paintEvent(QPaintEvent *event){

  QPainter painter(this);

  Car* car = new Car(-45,QPoint(150,150),QPoint(0,0));
  Car* car2 = new Car(0,QPoint(150,150),QPoint(0,0));
  Car* car3 = new Car(45,QPoint(150,150),QPoint(0,0));
  add_object(car);   add_object(car3); add_object(car2);

  for(auto obj : list_to_draw){
    obj->draw(&painter);
  }

 
  painter.drawPixmap(265,275,QPixmap(":/pic/bear.png"));

}
