#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "argumentsbuilder.h"
#include "magnetsmodel.h"
#include "modeldatabuilder.h"
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("qBitMagnet");
    loadModelData();

    connect(&_reader, &DataReader::dataChanged, this, &MainWindow::loadModelData);
}

void MainWindow::loadModelData()
{
    QStringList rawData = _reader.read();
    _modelData = ModelDataBuilder::build(rawData);

    MagnetsModel* model = new MagnetsModel(_modelData);

    ui->tableView->setModel(model);

    _reader.checkChange();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

