#ifndef  _GOBJECT_H_
#define  _GOBJECT_H_

class QPainter;

class GObject {

public:
  virtual void draw(QPainter* painter) = 0;
  
};



#endif
