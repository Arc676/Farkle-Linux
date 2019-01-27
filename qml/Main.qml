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

import QtQuick 2.4
import QtQuick.Layouts 1.1
import Ubuntu.Components 1.3

import FarkleBackend 1.0

MainView {
	id: root
	objectName: 'mainView'
	applicationName: 'farkle.arc676'
	automaticOrientation: true

	width: units.gu(45)
	height: units.gu(75)
	property real margin: units.gu(2)

	function dieTapped(index) {
		var dice = [die1, die2, die3, die4, die5, die6]
		if (FarkleBackend.hasFarkled) {
			FarkleBackend.endTurn()
		} else {
			FarkleBackend.toggle(index)
			updateDie(dice[index], index)
		}
	}

	function updateDie(die, index) {
		die.color = "#ffffff"
		die.die.source = "dice/" + FarkleBackend.getValue(index) + ".png"
		var state = FarkleBackend.dieState(index)
		if (state == FarkleBackend.UNAVAILABLE) {
			die.die.opacity = 0.5
		} else {
			die.die.opacity = 1.0
			switch (state) {
				case FarkleBackend.JUST_PICKED:
					die.color = "#00ff00"
					break;
				case FarkleBackend.UNPICKABLE:
					die.color = "#ff0000"
					break;
				default:
					break;
			}
		}
	}

	Connections {
		target: FarkleBackend
		onUpdateState: {
			var dice = [die1, die2, die3, die4, die5, die6]
			for (var i = 0; i < 6; i++) {
				updateDie(dice[i], i)
			}
		}

		onUpdateSelection: {
			selectionsTable.model.emitReset()
			if (FarkleBackend.accumulatedPoints == 0) {
				bankButton.text = i18n.tr("Bank")
			} else {
				bankButton.text = i18n.tr("Bank") + " (" + FarkleBackend.accumulatedPoints + ")"
			}
		}

		onUpdateButtons: {
			rollButton.enabled = FarkleBackend.buttonEnabled(FarkleBackend.ROLL_BUTTON)
			selButton.enabled = FarkleBackend.buttonEnabled(FarkleBackend.SELECT_BUTTON)
			bankButton.enabled = FarkleBackend.buttonEnabled(FarkleBackend.BANK_BUTTON)
		}

		onNextPlayer: {
			selectionsTable.model.loadPlayer(FarkleBackend.getCurrentPlayer())
			leaderboardTable.model.emitReset()
			bankButton.text = i18n.tr("Bank")
		}
	}

	Page {
		anchors.fill: parent

		header: PageHeader {
			id: header
			title: i18n.tr('Farkle')
		}

		Row {
			id: dieRow
			anchors {
				top: header.bottom
				topMargin: margin
				left: parent.left
				leftMargin: margin
				right: parent.right
				rightMargin: margin
			}

			spacing: (width - 6 * die1.rectSize - 2 * margin) / 5

			DieContainer {
				id: die1
				defaultSource: "dice/1.png"
				dieIndex: 0
			}

			DieContainer {
				id: die2
				defaultSource: "dice/2.png"
				dieIndex: 1
			}

			DieContainer {
				id: die3
				defaultSource: "dice/3.png"
				dieIndex: 2
			}

			DieContainer {
				id: die4
				defaultSource: "dice/4.png"
				dieIndex: 3
			}

			DieContainer {
				id: die5
				defaultSource: "dice/5.png"
				dieIndex: 4
			}

			DieContainer {
				id: die6
				defaultSource: "dice/6.png"
				dieIndex: 5
			}

		}

		Column {
			id: controlsCol
			width: parent.width
			spacing: margin
			anchors {
				top: dieRow.bottom
				topMargin: margin
			}

			Button {
				id: rollButton
				width: parent.width
				text: i18n.tr('Roll')
				anchors {
					left: parent.left
					right: parent.right
					leftMargin: margin
					rightMargin: margin
				}
				onClicked: {
					if (FarkleBackend.gameInProgress) {
						FarkleBackend.rollDice();
					} else {
						FarkleBackend.startGame(1, 10)
						leaderboardTable.model.loadLeaderboard(FarkleBackend.getLeaderboard())
					}
				}
			}

			Button {
				id: selButton
				width: parent.width
				text: i18n.tr('Confirm selection')
				anchors {
					left: parent.left
					right: parent.right
					leftMargin: margin
					rightMargin: margin
				}
				onClicked: FarkleBackend.confirmSelection()
			}

			Button {
				id: bankButton
				width: parent.width
				text: i18n.tr('Bank')
				anchors {
					left: parent.left
					right: parent.right
					leftMargin: margin
					rightMargin: margin
				}
				onClicked: FarkleBackend.bank()
			}

			Label {
				id: selectionsLabel
				width: parent.width
				text: i18n.tr('Selections')
				anchors {
					left: parent.left
					right: parent.right
					leftMargin: margin
				}
			}

			ListView {
				id: selectionsTable
				width: parent.width
				height: units.gu(15)
				model: SelectionsModel {}
				delegate: Rectangle {
					width: parent.width
					height: selText.height
					Text {
						id: selText
						text: selection
						anchors.left: parent.left
						anchors.leftMargin: margin * 2
					}
					Text {
						text: value
						anchors.right: parent.right
						anchors.rightMargin: margin * 2
					}
				}
			}

			Label {
				id: leaderboardLabel
				width: parent.width
				text: i18n.tr('Leaderboard')
				anchors {
					left: parent.left
					right: parent.right
					leftMargin: margin
				}
			}

			ListView {
				id: leaderboardTable
				width: parent.width
				height: units.gu(15)
				model: LeaderboardModel {}
				delegate: Rectangle {
					width: parent.width
					height: pNameText.height
					Text {
						id: pNameText
						text: playerName
						anchors.left: parent.left
						anchors.leftMargin: margin * 2
					}
					Text {
						text: score
						anchors.right: parent.right
						anchors.rightMargin: margin * 2
					}
				}
			}
		}
	}
}
