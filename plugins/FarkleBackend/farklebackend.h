//Copyright (C) 2018  Arc676/Alessandro Vinciguerra <alesvinciguerra@gmail.com>

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation (version 3) with the exception that
//linking the OpenSSL library is allowed.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef FARKLEBACKEND_H
#define FARKLEBACKEND_H

#include <QObject>

#include "libfarkle.h"

class FarkleBackend: public QObject {
	Q_OBJECT

	GameState state;
	Roll* roll = nullptr;
	Player** players = nullptr;
	int turn = 0;
	int turns = 0;
	int pCount = 0;
	int currentPlayer = 0;

public:
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
signals:
	/**
	 * Indicates to the UI that the dice' states
	 * have changed
	 */
	void updateState();
};

#endif
