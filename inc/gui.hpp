#ifndef  _GUI_H_
#define  _GUI_H_
#include <QMainWindow>

class Drawer;
class QPushButton;
class CentralWidget;
class QAction;
class QMenu;

class MainWindow : public QMainWindow {
  
  Q_OBJECT;
  
public:
  MainWindow();
  ~MainWindow();
  
  
private:
  CentralWidget* central; 

  void createActions();
  void createMenus();
  void createToolBars();
  void createStatusBar();
  
  QMenu *fileMenu;
  QMenu *editMenu;
  QMenu *helpMenu;
  QToolBar *fileToolBar;
  QToolBar *editToolBar;
  QAction *newAct;
  QAction *exitAct;
  QAction *editAct;
  QAction *aboutAct;

public slots:
  void noGame();

private slots:
  void newGame();
  void edit();
  void about();
    
  
};

class CentralWidget : public QWidget {

  Q_OBJECT;

public:
  CentralWidget(QWidget* parent);
  ~CentralWidget();
  
private:

  Drawer* canva;
  
  QPushButton *quit_button;

signals:  
  void gameEnded();

};

#endif
