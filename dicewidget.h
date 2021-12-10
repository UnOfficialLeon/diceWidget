#ifndef DICEWIDGET_H
#define DICEWIDGET_H
#include <QMouseEvent>
#include <QtWidgets>

#define  MIN_DICE_SIZE 64

class DiceWidget : public QWidget
{
  Q_OBJECT
  private:
    int   value;
    QRect diceRect;
    double   dotRadius;
    double   dotStep;
    bool mayRoll = true;

    bool clickStarted;

    void drawDot( QPainter* painter, QPoint pos );
    void drawCenterDot( QPainter* painter );
    void drawTopLeftBottomRightDots( QPainter* painter );
    void drawTopRightBottomLeftDots( QPainter* painter );
    void drawOuterMiddleDots( QPainter* painter );
    void drawDiceBackGround( QPainter* painter );
    void drawDiceBackGrounds( QPainter* painter );
    void drawDiceDots( QPainter* painter );




  public:
    explicit DiceWidget( QWidget* parent = nullptr );
    int getValue() const;

    bool getMayRoll( void ) const;

  public slots:
    void rollDiceSlot( void );
    void setMayRoll( bool value );
    void toggleMayRoll( void );
    void enableMayRoll( void );
    void disableMayRoll( void );

  protected:
    virtual void resizeEvent( QResizeEvent* event );
    virtual void paintEvent( QPaintEvent* event );

    void mousePressEvent ( QMouseEvent * event );
    void mouseReleaseEvent ( QMouseEvent * event );


  signals:
    void valueChanged(int newValue);
    void clicked( void );
};

#endif // DICEWIDGET_H
