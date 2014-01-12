#ifndef  _ENGINE_H_
#define  _ENGINE_H_
#include <QTimer>
#include <QWidget>

#include <iostream>

class Car;

class Engine : public QWidget {

  Q_OBJECT;

public:
  Engine(QWidget* parent);
  ~Engine(){
    std::cout << "Engine is being destroyed!" << std::endl;
  }

  Car* getPlayer(){
    return player;
  };

private slots:
  void update();
  void intCar(Car* c);

private:
  QTimer timer;
  QList<Car*> ai_list;
  Car* player;
  int dt;


};

#endif
