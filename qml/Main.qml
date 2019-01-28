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

MainView {
	id: root
	objectName: 'mainView'
	applicationName: 'farkle.arc676'
	automaticOrientation: true

	width: units.gu(45)
	height: units.gu(75)
	property real margin: units.gu(2)

	Page {
		header: PageHeader {
			id: header
			title: i18n.tr('Farkle')
		}

		Row {
			id: navRow
			anchors {
				top: header.bottom
				topMargin: margin
				left: parent.left
				leftMargin: margin
				right: parent.right
				rightMargin: margin
			}
			spacing: margin

			Button {
				id: gameButton
				text: i18n.tr("Play Game")
				onClicked: pageViewer.state = "GameView"
			}

			Button {
				id: setupButton
				text: i18n.tr("Game Settings")
				onClicked: pageViewer.state = "SetupView"
			}

			Button {
				id: aboutButton
				text: i18n.tr("About Farkle")
				onClicked: pageViewer.state = "AboutView"
			}
		}

		Rectangle {
			id: pageViewer
			anchors {
				top: navRow.bottom
				left: parent.left
				right: parent.right
				bottom: parent.bottom
			}
			
			Component.onCompleted: state = "GameView"

			GameView {
				id: gamePage
				setup: setupPage
				visible: false
			}

			SetupView {
				id: setupPage
				visible: false
			}

			AboutView {
				id: aboutPage
				visible: false
			}

			states: [
				State {
					name: "GameView"
					PropertyChanges {
						target: gamePage
						visible: true
					}
				},
				State {
					name: "SetupView"
					PropertyChanges {
						target: setupPage
						visible: true
					}
				},
				State {
					name: "AboutView"
					PropertyChanges {
						target: aboutPage
						visible: true
					}
				}
			]
		}
	}
}
