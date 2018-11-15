#include "mainwindow.h"
#include "readjson.h"
#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFile file("/home/sajesh/Qt/config_analog.json");
    const int nos = 5;
    janalog *analog_ptr = new janalog[nos];
    analog_ptr = analog_json(file, nos);



    QFile file1("/home/sajesh/Qt/config_digital.json");
    const int nos1 = 5;
    jdigital *digital_ptr = new jdigital[nos];
    digital_ptr = digital_json(file1, nos1);

    w.show();
    return a.exec();
}
