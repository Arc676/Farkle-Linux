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
	if (roll) {
		free(roll);
	}
	if (players) {
		for (int i = 0; i < this->pCount; i++) {
			freePlayer(players[i]);
		}
		free(players);
		free(leaderboard);
	}

	turns = turnLimit;
	this->pCount = pCount;

	accumulatedPoints = 0;
	turn = 0;

	roll = (Roll*)malloc(sizeof(Roll));
	initRoll(roll);

	players = (Player**)malloc(pCount * sizeof(Player*));
	leaderboard = (Player**)malloc(pCount * sizeof(Player*));
	for (int i = 0; i < pCount; i++) {
		char* name = (char*)malloc(10);
		sprintf(name, "Player %d", i);
		players[i] = createPlayer(name);
		leaderboard[i] = players[i];
	}
	gameInProgress = true;
	enterState(FIRST_ROLL);
	emit nextPlayer();
}

void FarkleBackend::rollDice() {
	newRoll(roll);
	Selection* sel = (Selection*)malloc(sizeof(Selection));
	RollType type = determineRollType(roll, sel);
	switch (type) {
	case FARKLE:
		emptyHand(players[currentPlayer]);
		enterState(TURN_ENDED);
		break;
	case STRAIGHT:
	case TRIPLE_PAIR:
		updateSelectionValue(sel);
		enterState(ROLLING);
		break;
	default:
		enterState(PICKING);
		break;
	}
	emit updateState();
}

void FarkleBackend::confirmSelection() {
	Selection* sel = (Selection*)malloc(sizeof(Selection));
	if (constructSelection(roll, sel)) {
		enterState(ROLLING);
		updateSelectionValue(sel);
	} else {
		deselectRoll(roll);
	}
}

void FarkleBackend::bank() {
	bankPoints(players[currentPlayer]);
	endTurn();
}

void FarkleBackend::endTurn() {
	enterState(FIRST_ROLL);
	setupNextTurn();

	if (currentPlayer == 0) {
		turn++;
		if (turn > turns) {
			gameInProgress = false;
			enterState(TURN_ENDED);
			return;
		}
	}
}

int FarkleBackend::getValue(int index) {
	return roll->dice[index].value;
}

void FarkleBackend::toggle(int index) {
	toggleDie(roll, index);
}

void FarkleBackend::setupNextTurn() {
	currentPlayer = (currentPlayer + 1) % pCount;
	accumulatedPoints = 0;
	initRoll(roll);
	sortPlayers(leaderboard, pCount);
	emit nextPlayer();
}

void FarkleBackend::updateSelectionValue(Selection* sel) {
	accumulatedPoints += sel->value;
	appendSelection(players[currentPlayer], sel);
	emit updateSelection();
}

void FarkleBackend::enterState(GameState state) {
	this->state = state;
	emit updateButtons();
}

bool FarkleBackend::buttonEnabled(int button) {
	switch (button) {
	case ROLL_BUTTON:
		return state & ROLLING;
	case SELECT_BUTTON:
		return state == PICKING;
	case BANK_BUTTON:
		return state == ROLLING;
	}
	return false;
}

PlayerWrapper* FarkleBackend::getCurrentPlayer() {
	PlayerWrapper* wrapper = new PlayerWrapper();
	wrapper->setPlayer(players[currentPlayer]);
	return wrapper;
}
