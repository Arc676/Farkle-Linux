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

#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"

void FarkleBackendPlugin::registerTypes(const char *uri) {
	qmlRegisterSingletonType<FarkleBackend>(uri, 1, 0, "FarkleBackend", [](QQmlEngine*, QJSEngine*) -> QObject* { return new FarkleBackend; });
	qmlRegisterType<SelectionsModel>(uri, 1, 0, "SelectionsModel");
	qmlRegisterType<LeaderboardModel>(uri, 1, 0, "LeaderboardModel");
	qmlRegisterType<PlayerWrapper>(uri, 1, 0, "PlayerWrapper");
	srand(time(NULL));
}
