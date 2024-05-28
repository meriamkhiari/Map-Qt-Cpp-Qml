#include "test.h" // Include the header file for the Test class
#include "map.h"  // Include the header file for the Map class

#include "ui_test.h"

test::test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
}

test::~test()
{
    delete ui;
}

void test::on_pushButton_map_clicked()
{
    // Create a new instance of the Map UI
    Map *mapUI = new Map();

    // Show the Map UI
    mapUI->show();

    // Connect the close event of the Map UI to delete the Map UI instance when closed
    connect(mapUI, &Map::closed, mapUI, &Map::deleteLater);
}



