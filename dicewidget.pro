TEMPLATE     = app
TARGET       = dicewidget
INCLUDEPATH += .
QT          += widgets

# Input
SOURCES     += main.cpp dicewidget.cpp \
    mainform.cpp
HEADERS     +=          dicewidget.h \
    mainform.h

FORMS += \
        mainform.ui
