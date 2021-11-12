#include <QApplication>
#include "mainform.h"
#include <stdlib.h>
#include <time.h>

int main( int argc, char** argv )
{
  srand( unsigned( time( nullptr ) ) );
  QApplication app( argc, argv );
  // Hauptfenster erstellen
  MainForm mainForm;
  // Hauptfenster anzeigen
  mainForm.show();
  return app.exec();
}
