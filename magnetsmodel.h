#ifndef MAGNETSMODEL_H
#define MAGNETSMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QList>
#include "tablerowdata.h"

class MagnetsModel : public QAbstractTableModel
{
        Q_OBJECT
    public:
        explicit MagnetsModel(QList<TableRowData> data, QObject *parent = nullptr);
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    private:
        QList<TableRowData> _data;
};

#endif // MAGNETSMODEL_H
