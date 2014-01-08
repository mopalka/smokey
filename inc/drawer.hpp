#ifndef  _DRAWER_H_
#define  _DRAWER_H_
#include <QWidget>

class QPainter;

class Drawer : public QWidget {
  
  Q_OBJECT;
  
public:
  Drawer(QWidget* parent);
  ~Drawer();

protected:
  void paintEvent(QPainter* painter);
  
};

#endif
