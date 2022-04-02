#include <QCoreApplication>
#include <QStringList>
#include "argumentsbuilder.h"

Arguments ArgumentsBuilder::buildArguments()
{
    Arguments result;

    QStringList args = QCoreApplication::arguments();

    if (args.size() <= 1)
    {
        return result;
    }

    result.isNull = false;
    result.TorrentName = args[1];
    result.Torrentsize = args[2];
    result.Currenttracker = args[3];
    result.Infohashv1 = args[4];
    result.Infohashv2 = args[5];

    return result;
}
