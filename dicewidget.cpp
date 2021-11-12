#include "dicewidget.h"
#include <stdlib.h>

DiceWidget::DiceWidget(QWidget *parent)
  : QWidget(parent), value(rand() % 6+1)
{
  setMinimumSize(MIN_DICE_SIZE, MIN_DICE_SIZE);

}

void DiceWidget::paintEvent(QPaintEvent* /*event*/)
{
/**  int diceSize;
  if (width() < height())
    diceSize = width();
  else
    diceSize = height(); **/
  int diceSize = width() < height() ? width() : height();
  diceSize--;
//  int xPos = width() /2-diceSize/2;
//  int yPos = height()/2-diceSize/2;
  QRect diceRect(0, 0, diceSize, diceSize);
  diceRect.moveCenter(QPoint(0, 0));

  int dotRadius = diceSize/14;
  int dotStep = 4*dotRadius;

  QPainter painter (this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setPen(Qt::black);
  painter.setBrush(Qt::white);
  painter.translate(rect().center());
  painter.drawRoundedRect(diceRect,                                     diceSize/5, diceSize/5);
                        //-diceSize/2, -diceSize/2, diceSize, diceSize,
                        //xPos          yPos

  //Füllung für Punkte auf schwarz setzen
  painter.setBrush(Qt::black);

  switch(value){
    case 5:
      punkte(-dotStep, -dotStep, dotRadius);
      punkte(dotStep, dotStep, dotRadius);
      //painter.drawEllipse(QPoint(-dotStep, -dotStep), dotRadius, dotRadius);
      //painter.drawEllipse(QPoint(dotStep, dotStep), dotRadius, dotRadius);
    [[clang::fallthrough]];
    case 3:
      punkte(dotStep, -dotStep, dotRadius);
      punkte(-dotStep, dotStep, dotRadius);
      //painter.drawEllipse(QPoint(dotStep, -dotStep), dotRadius, dotRadius);
      //painter.drawEllipse(QPoint(-dotStep, dotStep), dotRadius, dotRadius);
    [[clang::fallthrough]];
    case 1:
      punkte(0, 0, dotRadius);
      //painter.drawEllipse(QPoint(), dotRadius, dotRadius);
    break;
    case 6:
      punkte(-dotStep, 0, dotRadius);
      punkte(dotStep, 0, dotRadius);
      //painter.drawEllipse(QPoint(-dotStep, 0), dotRadius, dotRadius);
      //painter.drawEllipse(QPoint(dotStep, 0), dotRadius, dotRadius);
    [[clang::fallthrough]];
    case 4:
      punkte(-dotStep, dotStep, dotRadius);
      punkte(dotStep, -dotStep, dotRadius);
      //painter.drawEllipse(QPoint(-dotStep, dotStep), dotRadius, dotRadius);
      //painter.drawEllipse(QPoint(dotStep, -dotStep), dotRadius, dotRadius);
    [[clang::fallthrough]];
    case 2:
      punkte(-dotStep, -dotStep, dotRadius);
      punkte(dotStep, dotStep, dotRadius);
      //painter.drawEllipse(QPoint(-dotStep, -dotStep), dotRadius, dotRadius);
      //painter.drawEllipse(QPoint(dotStep, dotStep), dotRadius, dotRadius);
    break;
  }
}

void punkte(int stepX, int stepY, int radius){
  painter.drawEllipse(QPoint(stepX, stepY), radius, radius);
}
