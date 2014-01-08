#include "drawer.hpp"

Drawer::Drawer(QWidget* parent) : QWidget(parent) {
  
  setPalette(QPalette(QColor(200,200,200)));
  setAutoFillBackground(true);
  setFixedHeight(400);
  setFixedWidth(400);
}

Drawer::~Drawer(){

}
