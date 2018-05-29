#ifndef FARKLEBACKEND_H
#define FARKLEBACKEND_H

#include <QObject>

#include "libfarkle.h"

class FarkleBackend: public QObject {
    Q_OBJECT

    GameState state;
    Roll* roll;
    Player** players;
    int turn = 0;
    int turns = 0;
    int pCount = 0;
    int currentPlayer = 0;

public:
    Q_INVOKABLE void startGame(int, int);
    Q_INVOKABLE void rollDice();
    Q_INVOKABLE void confirmSelection();
    Q_INVOKABLE void bank();
};

#endif
