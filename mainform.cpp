#include "mainform.h"
#include "dicewidget.h"

MainForm::MainForm( QWidget* parent )
  : QWidget( parent )
{
  QHBoxLayout* diceLayout = new QHBoxLayout( this );
  QPushButton* btnRollDice = new QPushButton( "&Würfeln" );
  diceLayout->addWidget( btnRollDice );
  for( int i = 0; i < DICE_COUNT; i++ )
  {
    DiceWidget* newDice = new DiceWidget;
    diceLayout->addWidget( newDice );
    dice[ i ] = newDice;
    connect( btnRollDice, SIGNAL( clicked() ),
             newDice, SLOT( rollDiceSlot() ) );
  }
}
