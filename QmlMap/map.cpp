#include "map.h"
#include "ui_map.h"
#include <QQuickItem>
#include <QDebug>
#include <QTimer>

Map::Map(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Map)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();
    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));
    emit setCenter(36.000, 10.000);
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(onAddButtonClicked()));
}

Map::~Map()
{
    delete ui;
}

void Map::setLatitude(double newLatitude)
{
    latitude = newLatitude;
}

void Map::setLongitude(double newLongitude)
{
    longitude = newLongitude;
}

double Map::getLatitude() const
{
    return latitude;
}

double Map::getLongitude() const
{
    return longitude;
}

void Map::onAddButtonClicked()
{
    addMarkerToDatabase();
}

void Map::addMarkerToDatabase()
{
    double newLatitude = ui->lineEdit_lat->text().toDouble();
    double newLongitude = ui->lineEdit_long->text().toDouble();
    qDebug() << "Retrieved Latitude:" << newLatitude << "Longitude:" << newLongitude;
    addMarkerToMap(newLatitude, newLongitude);
}

void Map::addMarkerToMap(double newLatitude, double newLongitude)
{
    qDebug() << "Adding marker with Latitude:" << newLatitude << "Longitude:" << newLongitude;
    emit addMarker(newLatitude, newLongitude);
}
