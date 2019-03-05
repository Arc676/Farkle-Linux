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
	id: aboutPage
	anchors.fill: parent

	ScrollView {
		id: scroll
		anchors.fill: parent
		anchors.topMargin: margin

		Column {
			width: scroll.width
			spacing: margin

			WrappingLabel {
				text: "Farkle - " +i18n.tr("written by Arc676/Alessandro Vinciguerra. Project available under") + " GPLv3. Copyright 2018-9 Arc676/Alessandro Vinciguerra <alesvinciguerra@gmail.com>"
			}

			WrappingLabel {
				text: i18n.tr("This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation (version 3).")
			}

			WrappingLabel {
				text: i18n.tr("This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.")
			}

			WrappingLabel {
				text: i18n.tr("For the full license text, visit the <a href='https://github.com/Arc676/Farkle-Linux'>repository</a> or the <a href='http://www.gnu.org/licenses/'>GNU licenses page</a>")
			}

			WrappingLabel {
				text: i18n.tr("%1 assets").arg("<a href='http://creativecommons.org/licenses/by/3.0/'>CC BY 3.0</a>")
				textSize: Label.Large
			}

			WrappingLabel {
				text: i18n.tr("Application icon by <a href='http://www.freepik.com'>Freepik</a>")
			}

			WrappingLabel {
				text: i18n.tr("<a href='https://freesound.org/people/kiddpark/sounds/201159/'>Bank sound effect</a> by kiddpark")
			}

			WrappingLabel {
				text: i18n.tr("<a href='https://freesound.org/people/grunz/sounds/109662/'>Triple Pair</a> and <a href='https://freesound.org/people/grunz/sounds/109663/'>Straight</a> sound effects by grunz")
			}

			WrappingLabel {
				text: i18n.tr("<a href='http://creativecommons.org/publicdomain/zero/1.0/'>CC0</a> assets")
				textSize: Label.Large
			}

			WrappingLabel {
				text: i18n.tr("<a href='https://freesound.org/people/nettimato/sounds/353975/'>Dice rolling sounds</a> by nettimato")
			}

			WrappingLabel {
				text: i18n.tr("<a href='https://freesound.org/people/fins/sounds/171673/'>Farkle sound effect</a> by fins")
			}

			WrappingLabel {
				text: i18n.tr("<a href='https://freesound.org/people/KorgMS2000B/sounds/54405/'>Die selection ticking sound effect</a> by KorgMS2000B")
			}

			WrappingLabel {
				text: i18n.tr("%1 assets").arg("<a href='https://creativecommons.org/licenses/by-nc-sa/4.0/'>CC BY-NC-SA 4.0</a>")
				textSize: Label.Large
			}

			WrappingLabel {
				text: i18n.tr("Dice sprites by Arc676/Alessandro Vinciguerra")
			}
		}
	}
}
