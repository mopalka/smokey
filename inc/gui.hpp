#ifndef  _GUI_H_
#define  _GUI_H_
#include <QMainWindow>

class Drawer;
class QPushButton;
class QLabel;
class QLineEdit;
class CentralWidget;

class MainWindow : public QMainWindow {
  
  Q_OBJECT;
  
public:
  MainWindow();
  ~MainWindow();
  
  
private:
  CentralWidget* central; 
  
};

class CentralWidget : public QWidget {

  Q_OBJECT;

public:
  CentralWidget(QWidget* parent);
  ~CentralWidget();
  
private:

  Drawer* canva;
  
  QPushButton *in_button;
  QLabel *label_out;
  QLineEdit *in_name_line;
  QLineEdit *out_name_line;
  QPushButton *go_button;
  QPushButton *validate_button;
  QPushButton *solve_button;
  QPushButton *save_button;
  

};

#endif
