#include "gui.hpp"
#include "drawer.hpp"
#include <QtGui>
#include "car.hpp"


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

QMessageBox::about(this, tr("About Application"),
             tr("The <b>Application</b> is a simple "
                "2D car game equipped with AI."));

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
  canva = new Drawer(this);
  quit_button = new QPushButton(tr("Quit"));
  
  connect(quit_button,SIGNAL(clicked()),
	  this,SLOT(close()));
  connect(this,SIGNAL(gameEnded()),
	  parent,SLOT(noGame()));
  

  QVBoxLayout *left_layout = new QVBoxLayout;
  left_layout->addStretch();
  left_layout->addWidget(quit_button);


  QHBoxLayout *main_layout = new QHBoxLayout;
  main_layout->addWidget(canva);
  main_layout->addLayout(left_layout);

  setLayout(main_layout);

}

CentralWidget::~CentralWidget(){

  emit gameEnded();

}
