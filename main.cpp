#include "mainwindow.h"

#include <QApplication>
#include "argumentsbuilder.h"
#include "datawriter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Arguments args = ArgumentsBuilder::buildArguments();

    if (args.isNull)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }

    return DataWriter::write(args);
}
