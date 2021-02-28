#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent) {
  resize(500, 500);
  centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  layout = new QGridLayout(centralWidget);


  size = 5;
    srand(time(0));
    int *num = new int[3];
    for (int i = 0; i < 3; i++) {
        num[i] = rand() % (size * size);
    }
  fields.resize(size);
  for (int i = 0; i < size; ++i) {
    fields[i].resize(size);
    for (int j = 0; j < size; ++j) {
      bool bomb = false;
      for (int k = 0; k < 3; k++) {
        if (i * size + j == num[k])
          bomb = true;
      }
      Field *newfield = new Field(i, j, bomb, this);
      newfield->setText("*");
      fields[i][j] = newfield;
      layout->addWidget(newfield, i, j);
      connect(newfield, SIGNAL(moved(int, int)), this, SLOT(movehandler(int, int)));
    }
  }
}

MainWindow::~MainWindow() {
  for (int i = 0; i < fields.size(); ++i) {
    for (int j = 0; j < fields.size(); ++j) {
      delete fields[i][j];
    }
    fields[i].clear();
  }
  fields.clear();
  delete layout;
  delete centralWidget;
}

bool MainWindow::outBounds(int x,int y){
  return x<0||y<0||x>=size||y>=size;
}

int MainWindow::calcNear(int x, int y) {
  if(outBounds(x,y))return 0;
  int i=0;
  for (int offsetX=-1; offsetX<=1; offsetX++) {
    for (int offsetY=-1; offsetY<=1; offsetY++) {
      if (outBounds(offsetX+x, offsetY+y))continue;
      i += (int)fields[offsetX+x][offsetY+y]->getBomb();
    }
  }
  return i;
}

void MainWindow::reveal(int x, int y){
  if(outBounds(x,y))return;
  if(fields[x][y]->getRev())return;
  fields[x][y]->setRev();
    int i;
    if ((i = calcNear(x, y)) != 0) {
        QString str;
        str.setNum(i);
        fields[x][y]->setText(str); 
        fields[x][y]->setEnabled(false);
        return;
    } else {
        fields[x][y]->setText(""); 
    }
  fields[x][y]->setEnabled(false);

  reveal(x-1,y-1);
  reveal(x-1,y+1);
  reveal(x+1,y-1);
  reveal(x+1,y+1);
  reveal(x-1,y);
  reveal(x+1,y);
  reveal(x,y-1);
  reveal(x,y+1);
}

void MainWindow::movehandler(int row, int col) {
  qDebug() << row << col;
  if (fields[row][col]->getBomb()) {
    fields[row][col]->setText("BOMB!");
  } else {
    reveal(row, col);

  }
  fields[row][col]->setEnabled(false);
}
