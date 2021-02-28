#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>
#include <QString>

#include "field.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

  QWidget *centralWidget;
  QGridLayout *layout;
  QVector< QVector<Field *> > fields;

public:
    int size;
  MainWindow(QWidget *parent = NULL);
  ~MainWindow();
  void reveal(int x, int y);
  bool outBounds(int x, int y);
  int calcNear(int x, int y);

public slots:
  void movehandler(int row, int col);
};

#endif
