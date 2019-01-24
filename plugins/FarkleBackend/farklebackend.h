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

#ifndef FARKLEBACKEND_H
#define FARKLEBACKEND_H

#define ROLL_BUTTON 0
#define SELECT_BUTTON 1
#define BANK_BUTTON 2

#include <QObject>

#include "libfarkle.h"
#include "playerwrapper.h"

class FarkleBackend: public QObject {
	Q_OBJECT

	GameState state;
	Roll* roll = nullptr;
	Player** players = nullptr;
	Player** leaderboard = nullptr;
	int turn = 0;
	int turns = 0;
	int pCount = 0;
	int currentPlayer = 0;
	int accumulatedPoints = 0;

	bool gameInProgress;
public:
	Q_PROPERTY(bool gameInProgress MEMBER gameInProgress);

	/**
	 * Starts the game
	 * @param pCount Number of players
	 * @param turnLimit Maximum number of turns players can take before the game ends
	 */
	Q_INVOKABLE void startGame(int pCount, int turnLimit);

	/**
	 * Rolls the die pool
	 */
	Q_INVOKABLE void rollDice();

	/**
	 * Stores the user's die selection
	 */
	Q_INVOKABLE void confirmSelection();

	/**
	 * Banks the user's selections from the turn
	 */
	Q_INVOKABLE void bank();

	/**
	 * Gets the value of a die
	 * @param index Die index
	 * @return Value of the relevant die
	 */
	Q_INVOKABLE int getValue(int index);

	/**
	 * Toggles the selection state of a die
	 * @param index Die index
	 */
	Q_INVOKABLE void toggle(int index);

	Q_INVOKABLE bool buttonEnabled(int button);

	Q_INVOKABLE PlayerWrapper* getCurrentPlayer();

	Q_INVOKABLE PlayerWrapper* getLeaderboard();

	void setupNextTurn();

	void endTurn();

	void enterState(GameState state);

	void updateSelectionValue(Selection* sel);
signals:
	/**
	 * Indicates to the UI that the dice' states
	 * have changed
	 */
	void updateState();

	void updateSelection();

	void updateButtons();

	void nextPlayer();
};

#endif
