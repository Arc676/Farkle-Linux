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
	id: rulesPage
	anchors.fill: parent

	ScrollView {
		id: scroll
		anchors.fill: parent
		anchors.topMargin: margin

		Column {
			width: scroll.width
			spacing: margin

			WrappingLabel {
				text: i18n.tr("Gameplay rules")
			}

			WrappingLabel {
				text: i18n.tr("Farkle is a dice game in which the objective is to score as many points as possible. The number of turns is limited to an amount determined before the game begins.") 
                + "\n\n" 
                + i18n.tr("Players roll dice to score points in the following ways:")
                + "\n"
                + i18n.tr("A 1 is worth 100 points A 5 is worth 50 points Three of the same number are worth 100 times the number, except three 1s which are worth 1000 points instead; these dice must come up on the same roll, not separate ones Each additional occurrence of a number beyond the first three increases the value of that set of dice by 100 times the number (the points obtained by rolling three copies of that number) Players roll 6 dice and may select any subset of those dice to score points. Those dice are removed from the pool and the player may roll the remaining dice to score more points. If at any point none of the rolled dice can score points, the turn is considered a <farkle> and the player forfeits all their points from that turn. A player must remove at least one scoring die from the pool to reroll. A player may choose to stop rolling and <bank> any points they have already accumulated rather than reroll. Note that the probability of farkling is greater if the pool is smaller. If a player removes all 6 dice from the pool without farkling, that player keeps all their points from that turn in hand, puts all 6 dice back in the pool, and may reroll following the same rules as before.")
                + "\n"
            }
            
			WrappingLabel {
                text: i18n.tr("For more details and example rolls, please refer to the README in the repository for this app's backend library: ") + "<a href='https://github.com/Arc676/Farkle'>https://github.com/Arc676/Farkle</a> "
			}
		}
	}
}
