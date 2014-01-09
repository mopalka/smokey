#include "drawer.hpp"
#include <QPainter>
#include "gobject.hpp"

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

  for(auto obj : list_to_draw){
    obj->draw(&painter);
  }

 
  painter.drawPixmap(265,275,QPixmap(":/pic/bear.png"));

}
