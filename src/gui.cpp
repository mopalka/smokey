#include "gui.hpp"
#include "drawer.hpp"
#include <QtGui>

MainWindow::MainWindow()  {
  
  central = new CentralWidget(this);
  setCentralWidget(central);
    
  setWindowTitle(tr("Smokey!"));
  setFixedHeight(sizeHint().height());

  
}

MainWindow::~MainWindow(){

}


CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent) {

  canva = new Drawer(this);
  
  QHBoxLayout *main_layout = new QHBoxLayout;
  main_layout->addWidget(canva);

  setLayout(main_layout);

}

CentralWidget::~CentralWidget(){

}
