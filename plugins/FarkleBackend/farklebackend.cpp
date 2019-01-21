//Copyright (C) 2018-9 Arc676/Alessandro Vinciguerra <alesvinciguerra@gmail.com>

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation (version 3)

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

void FarkleBackend::rollDice() {
	newRoll(roll);
}

void FarkleBackend::confirmSelection() {
	Selection* sel = (Selection*)malloc(sizeof(Selection));
	if (constructSelection(roll, sel)) {
	} else {
		deselectRoll(roll);
	}
}

void FarkleBackend::bank() {
	bankPoints(players[currentPlayer]);
}

int FarkleBackend::getValue(int index) {
	return roll->dice[index].value;
}
