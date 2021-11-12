#include <QApplication>
#include "dicewidget.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
  srand(unsigned(time(nullptr)));
  QApplication app( argc, argv );
  // Würfelobjekt als Hauptfenster erzeugen
  DiceWidget mainForm;
  // und anzeigen
  mainForm.show();
  return app.exec();
}
