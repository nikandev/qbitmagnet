#include "magnetsmodel.h"

MagnetsModel::MagnetsModel(QList<TableRowData> data, QObject *parent)
    : QAbstractTableModel{parent},
      _data(data)
{
}

int MagnetsModel::rowCount(const QModelIndex& /*parent*/) const
{
    return _data.size();
}

int MagnetsModel::columnCount(const QModelIndex& /*parent*/) const
{
    return 3;
}

QVariant MagnetsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section) {
        case 0:
            return QString("Name");
        case 1:
            return QString("Size");
        case 2:
            return QString("Magnet");
        }
    }

    return QVariant();
}

QVariant MagnetsModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
            case 0:
            {
                if (index.row() < _data.size())
                {
                    return _data[index.row()].name;
                }

                break;
            }
            case 1:
            {
                if (index.row() < _data.size())
                {
                    return _data[index.row()].fileSize;
                }

                break;
            }
            case 2:
            {
                if (index.row() < _data.size())
                {
                    return _data[index.row()].magnet;
                }

                break;
            }
        }
    }

    return QVariant();
}
