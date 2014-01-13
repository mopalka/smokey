#include "gui.hpp"
#include "drawer.hpp"
#include "engine.hpp"
#include <QtGui>
#include "car.hpp"
#include "player_car.hpp"

#include <iostream>

MainWindow::MainWindow()  {
  
  central = new CentralWidget(this);
  setCentralWidget(central);
    
  
  createActions();
  createMenus();
  // createToolBars();
  createStatusBar();
  
  setWindowTitle(tr("Smokey!"));
  setFixedHeight(sizeHint().height());

}


MainWindow::~MainWindow(){

}


void MainWindow::createMenus()
{
  fileMenu = menuBar()->addMenu(tr("&Game"));
  fileMenu->addAction(newAct);
  fileMenu->addSeparator();
  fileMenu->addAction(exitAct);
  
  editMenu = menuBar()->addMenu(tr("&Edit"));
  editMenu->addAction(editAct);
  
  menuBar()->addSeparator();
  
  helpMenu = menuBar()->addMenu(tr("&Help"));
  helpMenu->addAction(aboutAct);

}


void MainWindow::createActions()
{
  newAct = new QAction(tr("&New"), this);
  newAct->setShortcuts(QKeySequence::New);
  newAct->setStatusTip(tr("A new game"));
  connect(newAct, SIGNAL(triggered()), this, SLOT(newGame()));
   
   
  exitAct = new QAction(tr("E&xit"), this);
  exitAct->setShortcuts(QKeySequence::Quit);
  exitAct->setStatusTip(tr("Exit the application"));
  connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

  editAct = new QAction(tr("Edit"), this);
  editAct->setStatusTip(tr("Edit the game parameters"));
  connect(editAct, SIGNAL(triggered()), this, SLOT(edit()));

  aboutAct = new QAction(tr("About"), this);
  aboutAct->setStatusTip(tr("Information abotu the application"));
  connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
   
}


void MainWindow::createStatusBar()
{
  statusBar()->showMessage(tr("Welcom to the game..."));
}


void MainWindow::about(){

  QMessageBox::about(this, tr("About This Game"),
		     tr("<p>The <b>Application</b> is a simple "
			"2D car game equipped with AI.</p>"
			"<p align=\"center\"> <img src=:/pic/bear.png /></p>"
			"<p>Oh! And in the game you are a bear.</p>"));

}

void MainWindow::newGame(){

  if(!central){
    central = new CentralWidget(this);
    setCentralWidget(central);
  } else {
    statusBar()->showMessage(tr("the game is on..."));
  }
  
}


void MainWindow::edit(){

}


void MainWindow::noGame(){

  central = 0;
  statusBar()->showMessage(tr("The game have ended..."));

}


CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent) {

  this->setAttribute(Qt::WA_DeleteOnClose);

  setFocusPolicy(Qt::StrongFocus);


  canva = new Drawer(this);
  engine = 0;
  
  quit_button = new QPushButton(tr("Quit"));
  quit_button->setFocusPolicy(Qt::NoFocus);
  start_engine_button = new QPushButton(tr("Start Engine"));
  start_engine_button->setFocusPolicy(Qt::NoFocus);

  connect(quit_button,SIGNAL(clicked()),
	  this,SLOT(close()));
  connect(start_engine_button,SIGNAL(clicked()),
	  this,SLOT(start_engine()));
  connect(this,SIGNAL(gameEnded()),
	  parent,SLOT(noGame()));
  

  QVBoxLayout *left_layout = new QVBoxLayout;
  left_layout->addStretch();
  left_layout->addWidget(start_engine_button);
  left_layout->addWidget(quit_button);


  QHBoxLayout *main_layout = new QHBoxLayout;
  main_layout->addWidget(canva);
  main_layout->addLayout(left_layout);

  setLayout(main_layout);

}

CentralWidget::~CentralWidget(){

  if(engine){
    delete engine;
  }
  emit gameEnded();

}


void CentralWidget::start_engine(){
  
  if(!engine){
    engine = new Engine(canva);
    canva->add_object(engine->getPlayer());
  }
  
}



void CentralWidget::keyPressEvent(QKeyEvent *event){
  
  if(engine){
    switch (event->key()){
    case Qt::Key_Up:
      engine->getPlayer()->setAcceleration(-1);
      break;
      
    case Qt::Key_Down:     
      engine->getPlayer()->setAcceleration(1);
      break;
      
    case Qt::Key_Right:
      engine->getPlayer()->setAngVelocity(1);
      break;

    case Qt::Key_Left:
      engine->getPlayer()->setAngVelocity(-1);
      break;

    default:
      QWidget::keyPressEvent(event);
    }
  }
}

void CentralWidget::keyReleaseEvent(QKeyEvent *event){
  
  if(engine){
    if(!event->isAutoRepeat()){    
      switch (event->key()){
      case Qt::Key_Up:
	engine->getPlayer()->setAcceleration(0);
	break;
	
      case Qt::Key_Down:
	engine->getPlayer()->setAcceleration(0);
	break;
	
      case Qt::Key_Right:
	engine->getPlayer()->setAngVelocity(0);
	break;
	
      case Qt::Key_Left:
	engine->getPlayer()->setAngVelocity(0);
	break;
	      
      default:
	QWidget::keyPressEvent(event);
      }
    }
  }  
}
