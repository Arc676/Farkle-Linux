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

#include "leaderboardmodel.h"

int LeaderboardModel::rowCount(const QModelIndex &parent) const {
	return pCount;
}

QVariant LeaderboardModel::data(const QModelIndex &index, int role) const {
	if (!leaderboard) {
		return QVariant();
	}
	int row = index.row();
	Player* player = leaderboard[row];
	switch (role) {
		case PlayerCol:
			return QVariant(QString(player->name));
		case ScoreCol:
			return QVariant(QString("%1").arg(player->score));
	}
	return QVariant();
}

QHash<int, QByteArray> LeaderboardModel::roleNames() const {
	QHash<int, QByteArray> names;
	names[PlayerCol] = "playerName";
	names[ScoreCol] = "score";
	return names;
}

void LeaderboardModel::loadLeaderboard(PlayerWrapper* wrapper) {
	leaderboard = wrapper->getLeaderboard();
	pCount = wrapper->getPlayerCount();
	delete wrapper;
	emitReset();
}
