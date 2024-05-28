#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class Map; }
QT_END_NAMESPACE

class Map : public QMainWindow
{
    Q_OBJECT

public:
    Map(QWidget *parent = nullptr);
    ~Map();

    // Getters and setters for latitude and longitude
    void setLatitude(double newLatitude);
    void setLongitude(double newLongitude);
    double getLatitude() const;
    double getLongitude() const;

    // Function to add a marker to the database
    void addMarkerToDatabase();

signals:
    // Signals for communication with QML
    void setCenter(QVariant latitude, QVariant longitude);
    void addMarker(QVariant latitude, QVariant longitude);

    void closed();
public slots:
    // Slot to handle button click and add a marker
    void onAddButtonClicked();

private:
    Ui::Map *ui;
    QObject *obj;

    double latitude;
    double longitude;

    // Function to add a marker and emit addMarker signal
    void addMarkerToMap(double newLatitude, double newLongitude);
};

#endif // MAP_H
