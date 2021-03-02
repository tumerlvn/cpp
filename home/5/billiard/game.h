#ifndef _GAME_H
#define _GAME_H

#include <QVector2D>
#include <QSize>
#include <QPixmap>

class Game {
  QSize size;
  QVector2D *position;
  QVector2D *velocity;
  int balls;
  double tau;
  double radius;
  QPixmap **texture_balls;
  friend class MainWindow;

public:
  Game();
  ~Game();
  double distance(QVector2D, QVector2D);
  void step();
  void draw(QPixmap *pixmap);
};

#endif
