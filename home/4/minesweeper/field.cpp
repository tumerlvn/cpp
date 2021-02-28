#include "field.h"
#include <QDebug>
#include <QSizePolicy>

Field::Field(int row, int col, bool bomb, QWidget *parent)
      :QPushButton(parent), row(row), col(col), bomb(bomb) {
  qDebug() << "CONSTRUCTOR";
  revealed = false;
  flag = false;
  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  connect(this, SIGNAL(clicked()), this, SLOT(clickhandler()));
}

bool Field::getBomb() {
    return bomb;
}

bool Field::getRev() {
    return revealed;
}

bool Field::getFlag() {
    return flag;
}

void Field::setFlag() {
    flag = !flag;
}

void Field::setRev() {
    revealed = true;
}

void Field::clickhandler() {
  qDebug() << "emit signal";
  emit moved(row, col);
}

