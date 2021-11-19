#include "mainform.h"
#include "dicewidget.h"

MainForm::MainForm( QWidget* parent )
    : QWidget( parent )
{
    setupUi(this);
    dice << dice_1 << dice_2 << dice_3 << dice_4 << dice_5;
    lcds << lcdNumber << lcdNumber_2 << lcdNumber_3 << lcdNumber_4 << lcdNumber_5;

    for( int i = 0; i < dice.count(); i++ ){
        connect( btnRollDice, SIGNAL( clicked() ),
                 dice[i], SLOT( rollDiceSlot() ) );
        lcds[i]->display(dice[i]->getValue());
        connect( dice[i], SIGNAL( valueChanged(int) ),
                 lcds[i], SLOT( display(int) ));
    }
}
