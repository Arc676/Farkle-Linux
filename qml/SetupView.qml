//Copyright (C) 2019 Arc676/Alessandro Vinciguerra <alesvinciguerra@gmail.com>

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

Rectangle {
	id: setupPage
	anchors.fill: parent

	property int turnCount: 10
	property int playerCount: 1
	property bool areSFXEnabled: true

	Column {
		anchors {
			fill: parent
			leftMargin: margin
			rightMargin: margin
			topMargin: margin
		}
		spacing: margin

		Label {
			id: pCount
			text: i18n.tr("Players: ") + 1
		}

		Row {
			id: pCountCtrl
			width: parent.width
			spacing: margin

			Button {
				id: pcm
				text: i18n.tr("Fewer players")
				onClicked: {
					if (setupPage.playerCount > 1) {
						setupPage.playerCount--
						pCount.text = i18n.tr("Players: ") + setupPage.playerCount
					}
				}
			}

			Button {
				id: pcp
				text: i18n.tr("More players")
				onClicked: {
					setupPage.playerCount++
					pCount.text = i18n.tr("Players: ") + setupPage.playerCount
				}
			}
		}

		Label {
			id: tCount
			text: i18n.tr("Turns: ") + 10
		}

		Row {
			id: tCountCtrl
			width: parent.width
			spacing: margin

			Button {
				id: tcm
				text: i18n.tr("Fewer turns")
				onClicked: {
					if (setupPage.turnCount > 1) {
						setupPage.turnCount--
						tCount.text = i18n.tr("Turns: ") + setupPage.turnCount
					}
				}
			}

			Button {
				id: tcp
				text: i18n.tr("More turns")
				onClicked: {
					setupPage.turnCount++
					tCount.text = i18n.tr("Turns: ") + setupPage.turnCount
				}
			}
		}

		CheckBox {
			id: enableSFX
			text: i18n.tr("Enable sound effects")
			checked: true

			onClicked: areSFXEnabled = checked
		}
	}
}
