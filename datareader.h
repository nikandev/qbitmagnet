#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>
#include <QTimer>
#include <QString>

class DataReader : public QObject
{
        Q_OBJECT
    public:
        explicit DataReader(QObject *parent = nullptr);
        QStringList read();
    public slots:
        void checkChange();
    private:
        QString _path;
        QString _fileName;
        QTimer _checkDelay;
        int _lastSize;
        void check();
    signals:
        void dataChanged();
};

#endif // DATAREADER_H
