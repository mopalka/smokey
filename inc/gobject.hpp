#ifndef  _GOBJECT_H_
#define  _GOBJECT_H_

class GObject {

public:
  GObject() = 0;
  virtual ~GObject();

protected:
  virtual void draw();

};

#endif
