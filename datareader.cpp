#include "datareader.h"
#include "QCoreApplication"
#include <QFileInfo>

#define Delay 5000 //ms

DataReader::DataReader(QObject *parent)
    : QObject{parent},
      _path(QCoreApplication::applicationDirPath()),
      _fileName("data.dat")
{
    QFileInfo info(_path + "/" + _fileName);
    _lastSize = info.size();


    connect(&_checkDelay, &QTimer::timeout, this, &DataReader::check);
    _checkDelay.start(Delay);
}

QStringList DataReader::read()
{
    QStringList result;

    QFile file(_path + "/" + _fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning("failed to open file");
        return result;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        result.append(line);
    }

    return result;
}

void DataReader::checkChange()
{
    _checkDelay.start(Delay);
}

void DataReader::check()
{
    QFileInfo info(_path + "/" + _fileName);

    {
        if (info.size() != _lastSize)
        {
            _checkDelay.stop();
            _lastSize = info.size();
            emit dataChanged();
        }
    }
}
