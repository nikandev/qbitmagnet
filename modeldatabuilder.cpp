#include "modeldatabuilder.h"
#include <QUrl>

QList<TableRowData> ModelDataBuilder::build(const QStringList& rawData)
{
    QList<TableRowData> result;

    for (QString s : rawData)
    {
        QList<QString> line = s.split(", ");
        TableRowData d;
        d.name = line[0];
        d.fileSize = line[1].toInt();
        d.magnet = buildMagnet(line);
        result.append(d);
    }

    return result;
}

QString ModelDataBuilder::buildMagnet(const QList<QString>& line)
{
    QString name = line[0];
    QString tracker = line[2].mid(4);
    QString hash1 = line[3];
    QString hash2 = line[4];

    if (hash2 == "-")
    {
        hash2 = "";
    }
    else
    {
        hash2 = "&xt=urn:btmh:1220" + hash2;
    }

    QString result = "magnet:?xt=urn:btih:" +
                     hash1 +
                     hash2 +
                     "&dn=" +
                     QUrl::toPercentEncoding(name) +
                     "&tr=udp" +
                     QUrl::toPercentEncoding(tracker) +
                     "&tr=http" +
                     QUrl::toPercentEncoding(tracker);

    return result;
}
