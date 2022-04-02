#ifndef MODELDATABUILDER_H
#define MODELDATABUILDER_H

#include <QList>
#include <QString>
#include "tablerowdata.h"

class ModelDataBuilder
{
    public:
        static QList<TableRowData> build(const QStringList& rawData);
    private:
        static QString buildMagnet(const QList<QString>& line);
};

#endif // MODELDATABUILDER_H
