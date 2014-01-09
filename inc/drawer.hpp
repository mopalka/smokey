#ifndef  _DRAWER_H_
#define  _DRAWER_H_
#include <QWidget>

class GObject;

class Drawer : public QWidget {
  
  Q_OBJECT;
  
public:
  Drawer(QWidget* parent);
  ~Drawer();
  
private:
  QList<GObject*> list_to_draw;

protected:
  void paintEvent(QPaintEvent *event);
  
public slots:
  void add_object(GObject* object){
    list_to_draw.push_back(object);
  };
  
};

#endif
