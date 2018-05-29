#ifndef LEADERBOARDMODEL_H
#define LEADERBOARDMODEL_H

#include <QAbstractTableModel>

class LeaderboardModel: public QAbstractTableModel {
    Q_OBJECT

public:
    QModelIndex parent(const QModelIndex &index) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif
