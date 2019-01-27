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

#ifndef SELECTIONSMODEL_H
#define SELECTIONSMODEL_H

#include <QString>

#include "model.h"
#include "libfarkle.h"

class SelectionsModel: public TwoColumnTableModel {
	Q_OBJECT

	Player* player = nullptr;

	enum {
		SelectionCol = Qt::UserRole,
		ValueCol
	};

public:
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	QHash<int, QByteArray> roleNames() const;

	/**
	 * Loads new player data
	 * @param wrapper A wrapper containing player data
	 */
	Q_INVOKABLE void loadPlayer(PlayerWrapper* wrapper);
};

#endif
