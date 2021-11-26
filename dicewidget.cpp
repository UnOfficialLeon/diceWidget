#include "dicewidget.h"
#include <stdlib.h>
#include <QPalette>

DiceWidget::DiceWidget( QWidget* parent )
  : QWidget( parent ), value( rand() % 6 + 1 )
{
    setMinimumSize( MIN_DICE_SIZE, MIN_DICE_SIZE );

}

void DiceWidget::rollDiceSlot( void )
{

  int newValue = rand() % 6 + 1;
  if(newValue != value){
    update();
    value=newValue;
    emit valueChanged(newValue);
  }
}



void DiceWidget::resizeEvent( QResizeEvent* /*event*/ )
{
  int diceSize = width() < height() ? width() : height();
  diceSize--;
  diceRect = QRect( 0, 0, diceSize, diceSize );
  diceRect.moveCenter( rect().center() );
  dotRadius = diceSize / 14.0;
  dotStep   = 4.0 * dotRadius;
}

void DiceWidget::paintEvent( QPaintEvent* /*event*/ )
{
  QPainter painter( this );
  painter.setRenderHint( QPainter::Antialiasing );
  drawDiceBackGround( &painter );
  drawDiceDots( &painter );
}

int DiceWidget::getValue() const
{
  return value;
}

void DiceWidget::drawDot( QPainter* painter, QPoint pos )
{
    painter->setBrush( palette().color( QPalette::LinkVisited ) );
    painter->drawEllipse( QPointF( pos.x() * dotStep, pos.y() * dotStep ),
                        dotRadius, dotRadius );
}

void DiceWidget::drawCenterDot( QPainter* painter )
{
  drawDot( painter, QPoint( 0, 0 ) );
}

void DiceWidget::drawTopLeftBottomRightDots( QPainter* painter )
{
  drawDot( painter, QPoint( -1, -1 ) );
  drawDot( painter, QPoint(  1,  1 ) );
}

void DiceWidget::drawTopRightBottomLeftDots( QPainter* painter )
{
  drawDot( painter, QPoint(  1, -1 ) );
  drawDot( painter, QPoint( -1,  1 ) );
}

void DiceWidget::drawOuterMiddleDots( QPainter* painter )
{
  drawDot( painter, QPoint(  1, 0 ) );
  drawDot( painter, QPoint( -1, 0 ) );
}

void DiceWidget::drawDiceBackGround( QPainter* painter )
{
  painter->setPen( Qt::black );
  //painter->setBrush( Qt::white );
  painter->setBrush( palette().color( QPalette::Link ) );
  painter->drawRoundedRect( diceRect, 25, 25, Qt::RelativeSize );
}

void DiceWidget::drawDiceDots( QPainter* painter )
{
  // Füllung für Punkte auf schwarz setzen
  painter->setBrush( Qt::black );
  painter->translate( rect().center() );
  switch( value )
  {
    case 5:
      drawTopLeftBottomRightDots( painter );
      [[clang::fallthrough]];
    case 3:
      drawTopRightBottomLeftDots( painter );
      [[clang::fallthrough]];
    case 1:
      drawCenterDot( painter );
    break;
    case 6:
      drawOuterMiddleDots( painter );
      [[clang::fallthrough]];
    case 4:
      drawTopRightBottomLeftDots( painter );
      [[clang::fallthrough]];
    case 2:
      drawTopLeftBottomRightDots( painter );
    break;
  }
}

void DiceWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) return;
    clickStarted = diceRect.contains(event->pos());
}

void DiceWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton || !clickStarted ) return;
    clickStarted = diceRect.contains(event->pos());
    emit clicked();
}
