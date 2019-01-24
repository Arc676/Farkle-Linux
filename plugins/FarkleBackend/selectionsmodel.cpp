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

#include "selectionsmodel.h"

int SelectionsModel::rowCount(const QModelIndex &parent) const {
	if (player) {
		return player->hand->timesSelected;
	}
	return 0;
}

QVariant SelectionsModel::data(const QModelIndex &index, int role) const {
	if (!player) {
		return QVariant();
	}
	int row = index.row();
	Selection* sel = player->hand->selections[row];
	if (!sel) {
		return QVariant();
	}
	switch (role) {
		case SelectionCol:
		{
			QString text = "";
			for (int i = 0; i < sel->dieCount; i++) {
				text.append(QString("%1 ").arg(sel->values[i]));
			}
			return QVariant(text);
		}
		case ValueCol:
			return QVariant(QString("%1").arg(sel->value));
	}
	return QVariant();
}

QHash<int, QByteArray> SelectionsModel::roleNames() const {
	QHash<int, QByteArray> names;
	names[SelectionCol] = "selection";
	names[ValueCol] = "value";
	return names;
}

void SelectionsModel::loadPlayer(PlayerWrapper* wrapper) {
	player = wrapper->getPlayer();
	delete wrapper;
	emitReset();
}
