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

#include <QObject>

#include "libfarkle.h"
#include "playerwrapper.h"

class FarkleBackend: public QObject {
	Q_OBJECT

	// game state
	GameState state;
	Roll* roll = nullptr;
	RollType rollType = SIMPLE;
	int pickable[6] = {0, 0, 0, 0, 0, 0};
	bool gameInProgress = false;

	// players
	Player** players = nullptr;
	Player** leaderboard = nullptr;

	// turn state
	int currentTurn = 0;
	int turnLimit = 0;
	int pCount = 0;
	int currentPlayer = 0;
	int accumulatedPoints = 0;
	bool hasFarkled = false;
public:
	Q_PROPERTY(bool gameInProgress MEMBER gameInProgress);
	Q_PROPERTY(bool hasFarkled MEMBER hasFarkled);
	Q_PROPERTY(int currentTurn MEMBER currentTurn);
	Q_PROPERTY(int turnLimit MEMBER turnLimit);
	Q_PROPERTY(int accumulatedPoints MEMBER accumulatedPoints);

	/**
	 * Identifies UI buttons
	 */
	enum ButtonType : int {
		ROLL_BUTTON,
		SELECT_BUTTON,
		BANK_BUTTON
	};
	Q_ENUMS(ButtonType)

	/**
	 * Indicates how the die sprite should be rendered
	 */
	enum DieRender : int {
		UNAVAILABLE,
		JUST_PICKED,
		UNPICKABLE,
		PICKABLE
	};
	Q_ENUMS(DieRender)

	/**
	 * Copy library RollType enum to expose to QML
	 */
	enum RollTypeQ : int {
		FARKLE_Q, SIMPLE_Q, TRIPLE_PAIR_Q, STRAIGHT_Q
	};
	Q_ENUMS(RollTypeQ)

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

	/**
	 * Determine whether a given button should be enabled
	 * given the game's current state
	 * @param button The button type to check
	 * @return Whether the specified button should be enabled
	 */
	Q_INVOKABLE bool buttonEnabled(ButtonType button);

	/**
	 * Determine the current state of a given die based on
	 * whether it has been, can, or cannot be picked
	 * @param index The die's index
	 * @return How the die should be rendered
	 */
	Q_INVOKABLE DieRender dieState(int index);

	/**
	 * Obtain the current player
	 * @return A wrapper containing a pointer to the player whose turn it currently is
	 */
	Q_INVOKABLE PlayerWrapper* getCurrentPlayer();

	/**
	 * Obtain the leaderboard
	 * @return A wrapper containing data regarding the leaderboard
	 */
	Q_INVOKABLE PlayerWrapper* getLeaderboard();

	/**
	 * Obtains the current player's name
	 * @return Name of player whose turn it currently is, or an empty string if there is no game in progress
	 */
	Q_INVOKABLE QString getCurrentPlayerName();

	/**
	 * Obtains the current player's score
	 * @return Score of player whose turn it currently is, or 0 if there is no game in progress
	 */
	Q_INVOKABLE int getCurrentPlayerScore();

	/**
	 * Obtains the latest roll type
	 * @return Roll type of the latest roll, typecast to RollTypeQ
	 */
	Q_INVOKABLE RollTypeQ getRollType();

	/**
	 * Sets up the game for the next player's turn
	 */
	void setupNextTurn();

	/**
	 * Ends the current turn
	 */
	Q_INVOKABLE void endTurn();

	/**
	 * Determines whether the game is in a state such that dice
	 * can be tapped
	 * @return Whether tapping the dice should have any effect
	 */
	Q_INVOKABLE bool canTapDice();

	/**
	 * Prepares the game for the given state
	 * @param state The game's new state
	 */
	void enterState(GameState state);

	/**
	 * Adds the given selection to the current player's hand
	 * and updates the game state
	 * @param sel The player's latest selection
	 */
	void updateSelectionValue(Selection* sel);
signals:
	/**
	 * Indicates to the UI that the dice' states
	 * have changed
	 */
	void updateState();

	/**
	 * Indicates that the player has made a selection
	 * and the selection table needs updating
	 */
	void updateSelection();

	/**
	 * Indicates to the UI that the game has entered another
	 * state and the buttons need to be enabled or
	 * disabled accordingly
	 */
	void updateButtons();

	/**
	 * Indicates that the turn has been passed to the next player
	 */
	void nextPlayer();
};

#endif
