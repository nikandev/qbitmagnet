#include <QFile>
#include <QTextStream>
#include "datawriter.h"
#include <QCoreApplication>

int DataWriter::write(const Arguments& args)
{
    QString path = QCoreApplication::applicationDirPath();
    QFile file(path + "/data.dat");

    if (!file.open(QIODevice::Append | QIODevice::Text))
        return 1;

    QTextStream out(&file);
    out << args.TorrentName << ", ";
    out << args.Torrentsize << ", ";
    out << args.Currenttracker << ", ";
    out << args.Infohashv1 << ", ";
    out << args.Infohashv2 << "\n";

    file.close();

    return 0;
}
