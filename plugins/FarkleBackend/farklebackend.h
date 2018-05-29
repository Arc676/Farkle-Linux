#ifndef FARKLEBACKEND_H
#define FARKLEBACKEND_H

#include <QObject>

#include "libfarkle.h"

class FarkleBackend: public QObject {
    Q_OBJECT

    GameState state;
    Roll* roll;
    Player** players;
    int turn, turns, pCount, currentPlayer;

public:
    Q_INVOKABLE void startGame(int, int);
    Q_INVOKABLE void newRoll();
    Q_INVOKABLE void confirmSelection();
    Q_INVOKABLE void bankPoints();
};

#endif
