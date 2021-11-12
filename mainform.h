#ifndef MAINFORM_H
#define MAINFORM_H

#include <QtWidgets>

#define DICE_COUNT 5

class DiceWidget;  // Forward Declaration

class MainForm : public QWidget
{
  Q_OBJECT
  private:
    DiceWidget* dice[ DICE_COUNT ];
    QLCDNumber* lcds[ DICE_COUNT ];

  public:
    explicit MainForm( QWidget* parent = nullptr );

};

#endif // MAINFORM_H
