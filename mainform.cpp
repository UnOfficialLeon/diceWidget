#include "mainform.h"
#include "dicewidget.h"

MainForm::MainForm( QWidget* parent )
    : QWidget( parent )
{
    setupUi(this);
    dice << dice_1 << dice_2 << dice_3 << dice_4 << dice_5;
    lcds << lcdNumber << lcdNumber_2 << lcdNumber_3 << lcdNumber_4 << lcdNumber_5;
//  QGridLayout* diceLayout = new QGridLayout( this );
//  QPushButton* btnRollDice = new QPushButton( "&Würfeln" );
//  diceLayout->addWidget( btnRollDice, 0, 0, 1, DICE_COUNT);
//  diceLayout->setRowMinimumHeight(2, 50);
      for( int i = 0; i < dice.count(); i++ ){
//    DiceWidget* newDice = new DiceWidget;
//    diceLayout->addWidget( newDice, 1, i, nullptr );
//    dice[ i ] = newDice;
//    connect( btnRollDice, SIGNAL( clicked() ),
//             newDice, SLOT( rollDiceSlot() ) );

//    QLCDNumber* newNumber = new QLCDNumber;
//    newNumber->setDigitCount(1);
//    //newNumber->setDecMode(); UNNÖTIG
//    diceLayout->addWidget( newNumber, 2, i);
//    lcds[i] = newNumber;
      lcds[i]->display(dice[i]->getValue());
//    connect( newDice, SIGNAL( valueChanged(int) ),
//               newNumber, SLOT( display(int) ));

    }



}
