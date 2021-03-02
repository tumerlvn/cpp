#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QtMath>

#include "game.h"

Game::Game() {
  size = QSize(600, 600);
  balls = 4;
  position = new QVector2D[balls];
  for (int i = 0; i < balls; i++) {
    position[i] = QVector2D(100 + 110 * i, 100 + 110 * i);
  }

  velocity = new QVector2D[balls];
  for (int i = 0; i < balls; i++) {
    velocity[i] = QVector2D(40.0 * qPow(-1, i), 50.0);
  }

  tau = 0.1;
  radius = 50.0;

  texture_balls = new QPixmap*[balls];

  for (int i = 0; i < balls; i++) {
    texture_balls[i] = new QPixmap("pictures/ball.png");
  }
}

void Game::step() {
  for (int i = 0; i < balls; i++) {


    QVector2D normal[] = { QVector2D(1, 0),
                           QVector2D(0, -1),
                           QVector2D(-1, 0),
                           QVector2D(0, 1) };
    QVector2D border[] = { QVector2D(radius, radius),
                           QVector2D(radius, size.height() - radius),
                           QVector2D(size.width() - radius, size.height() - radius),
                           QVector2D(size.width() - radius, radius) };
    for (int j = 0; j < 4; j++) {
      qreal normal_factor = QVector2D::dotProduct(position[i] - border[j], normal[j]);
      if (normal_factor < 0) {
        position[i] = position[i] - 2 * normal_factor * normal[j];
        velocity[i] = velocity[i] - 2 * QVector2D::dotProduct(velocity[i], normal[j]) * normal[j];
      }
    }

    qDebug() << position[i] << velocity[i];
  }
  for (int i = 0; i < balls; i++) {
    for (int j = 0; j < balls; j++) {
      if (j == i) continue;
      if ((position[i] - position[j]).length() <= 2 * radius) {
        QVector2D xDiff = position[i] - position[j];
        QVector2D x2Diff = position[j] - position[i];
        QVector2D vDiff = velocity[i] - velocity[j];
        QVector2D v2Diff = velocity[j] - velocity[i];
        velocity[i] = velocity[i] -  (QVector2D::dotProduct(vDiff, xDiff) / (xDiff.lengthSquared())) * xDiff ;
        velocity[j] = velocity[j] -  (QVector2D::dotProduct(v2Diff, x2Diff) / (x2Diff.lengthSquared())) * (x2Diff);
      }
    }
    position[i] = position[i] + tau * velocity[i];
  }
  // for (int i = 0; i < balls; i++) {
  //
  // }

}

void Game::draw(QPixmap *pixmap) {
  pixmap->fill(Qt::white);
  QPainter painter(pixmap);
  for (int i = 0; i < balls; i++) {
    painter.drawPixmap(position[i].x() - radius,
                       position[i].y() - radius,
                       *texture_balls[i]);
  }

}

Game::~Game() {
  for (int i = 0; i < balls; i++) {
    delete texture_balls[i];
  }
  delete [] texture_balls;
}
