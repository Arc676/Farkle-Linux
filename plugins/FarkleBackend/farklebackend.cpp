#include <QDebug>

#include "farklebackend.h"

void FarkleBackend::startGame(int pCount, int turnLimit) {
	if (!roll) {
		roll = (Roll*)malloc(sizeof(Roll));
	}
	turns = turnLimit;
	if (players) {
		for (int i = 0; i < this->pCount; i++) {
			freePlayer(players[i]);
		}
		free(players);
	}
	this->pCount = pCount;
	players = (Player**)malloc(pCount * sizeof(Player*));
	initRoll(roll);
}

void FarkleBackend::newRoll() {
	newRoll(roll);
}

void FarkleBackend::confirmSelection() {
	Selection* sel = (Selection*)malloc(sizeof(Selection));
        if (constructSelection(roll, sel)) {
        } else {
                deselectRoll(_roll);
        }
}

void FarkleBackend::bankPoints() {
	bankPoints(players[currentPlayer]);
}
