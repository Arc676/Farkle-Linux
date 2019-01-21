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

	Connections {
		target: FarkleBackend
		onUpdateState: {
			var dice = [die1, die2, die3, die4, die5, die6]
			for (var i = 0; i < 6; i++) {
				dice[i].source = "dice/" + FarkleBackend.getValue(i) + ".png"
			}
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

			spacing: (width - 6 * 32 - 2 * margin) / 5

			Image {
				id: die1
				source: "dice/1.png"
				MouseArea {
					anchors.fill: parent
					onClicked: FarkleBackend.toggle(0)
				}
			}

			Image {
				id: die2
				source: "dice/2.png"
				MouseArea {
					anchors.fill: parent
					onClicked: FarkleBackend.toggle(1)
				}
			}

			Image {
				id: die3
				source: "dice/3.png"
				MouseArea {
					anchors.fill: parent
					onClicked: FarkleBackend.toggle(2)
				}
			}

			Image {
				id: die4
				source: "dice/4.png"
				MouseArea {
					anchors.fill: parent
					onClicked: FarkleBackend.toggle(3)
				}
			}

			Image {
				id: die5
				source: "dice/5.png"
				MouseArea {
					anchors.fill: parent
					onClicked: FarkleBackend.toggle(4)
				}
			}

			Image {
				id: die6
				source: "dice/6.png"
				MouseArea {
					anchors.fill: parent
					onClicked: FarkleBackend.toggle(5)
				}
			}
		}

		Column {
			id: controlsRow
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
				onClicked: {
					if (FarkleBackend.gameInProgress) {
						FarkleBackend.rollDice();
					} else {
						FarkleBackend.startGame(1, 1)
					}
				}
			}

			Button {
				id: selButton
				width: parent.width
				text: i18n.tr('Confirm selection')
				onClicked: FarkleBackend.confirmSelection()
			}

			Button {
				id: bankButton
				width: parent.width
				text: i18n.tr('Bank')
				onClicked: FarkleBackend.bank()
			}

			ListView {
				id: selectionsTable
				width: parent.width
			}
		}

		Row {
			id: leaderboardColumn
			width: parent.width
			anchors {
				top: controlsRow.bottom
				topMargin: margin
			}

			ListView {
				id: leaderboardTable
				anchors.fill: parent
			}
		}
	}
}
