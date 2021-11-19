#ifndef MAINFORM_H
#define MAINFORM_H

#include <QtWidgets>
#include "ui_mainform.h"

//#define DICE_COUNT 5

class DiceWidget; // Forward Declaration

class MainForm : public QWidget,  private Ui::MainForm
{
  Q_OBJECT
  private:
    QList< DiceWidget* > dice;
    QList< QLCDNumber* > lcds;

  public:
    explicit MainForm( QWidget* parent = nullptr );

};

#endif // MAINFORM_H
