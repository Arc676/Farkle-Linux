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
	id: container

	property real rectSize: units.gu(6)
	property real spriteSize: units.gu(5)

	property url defaultSource
	property int dieIndex

	width: rectSize
	height: rectSize

	property Image die: die

	Image {
		id: die
		width: container.spriteSize
		height: container.spriteSize
		source: container.defaultSource
		anchors.centerIn: container
		MouseArea {
			anchors.fill: die
			onClicked: dieTapped(container.dieIndex)
		}
	}
}
