#include "mainform.h"
#include "dicewidget.h"

MainForm::MainForm( QWidget* parent )
  : QWidget( parent )
{
  QGridLayout* diceLayout = new QGridLayout( this );
  QPushButton* btnRollDice = new QPushButton( "&Würfeln" );
  diceLayout->addWidget( btnRollDice, 0, 0, 1, DICE_COUNT);
  diceLayout->setRowMinimumHeight(2, 50);
  for( int i = 0; i < DICE_COUNT; i++ ){
    DiceWidget* newDice = new DiceWidget;
    diceLayout->addWidget( newDice, 1, i, nullptr );
    dice[ i ] = newDice;
    connect( btnRollDice, SIGNAL( clicked() ),
             newDice, SLOT( rollDiceSlot() ) );


    QLCDNumber* newNumber = new QLCDNumber;
    newNumber->setDigitCount(1);
    //newNumber->setDecMode(); UNNÖTIG
    diceLayout->addWidget( newNumber, 2, i);
    lcds[i] = newNumber;
    connect( newDice, SIGNAL( valueChanged(int) ),
               newNumber, SLOT( display(int) ));

  }


}
