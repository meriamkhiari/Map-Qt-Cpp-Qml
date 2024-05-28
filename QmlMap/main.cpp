#include <QApplication>
#include "test.h" // Include the header file for Test class

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    test w; // Instantiate Test instead of Map
    w.show();
    return a.exec();
}
