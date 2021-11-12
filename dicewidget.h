#ifndef DICEWIDGET_H
#define DICEWIDGET_H

#include <QtWidgets>
#define MIN_DICE_SIZE 64

class DiceWidget : public QWidget
{
    Q_OBJECT
  private:
    int value;
    void punkte(int stepX, int stepY, int radius);

  public:
    explicit DiceWidget(QWidget *parent = nullptr);

  protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // DICEWIDGET_H
