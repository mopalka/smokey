#ifndef  _ENGINE_H_
#define  _ENGINE_H_
#include <QTimer>
#include <QWidget>
#include "obstacle.hpp"
#include <QVector>
#include <iostream>

class PlayerCar;
class Car;

class Engine : public QWidget {

  Q_OBJECT;

public:
  Engine(QWidget* parent);
  ~Engine(){
    std::cout << "Engine is being destroyed!" << std::endl;
    delete player;
  }

  PlayerCar* getPlayer(){
    return player;
  };

  QVector<Obstacle*> getObstacles(){
    return obstacles;
  };


private slots:
  void update();
  void intCar(Car* c);

private:
  bool checkCollisions();
  QTimer timer;
  QList<Car*> ai_list;
  QVector<Obstacle*> obstacles;
  PlayerCar* player;
  int dt;


};

#endif
