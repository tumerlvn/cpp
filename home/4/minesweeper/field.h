#ifndef FIELD_H
#define FIELD_H

#include <QPushButton>
#include <QWidget>

class Field : public QPushButton {
  Q_OBJECT
  int row, col;
  bool bomb;
  bool revealed;
  bool flag;
public:
  Field(int row, int col, bool bomb, QWidget *parent = NULL);
  bool getBomb();
  bool getRev();
  bool getFlag();
  void setRev();
  void setFlag();
signals:
  void moved(int row, int col);
public slots:
  void clickhandler();
};

#endif
