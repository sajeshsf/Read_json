#ifndef JDIGITAL_C_H
#define JDIGITAL_C_H

#include "jdigital.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

class jdigital_c
{
private:

   jdigital *ptr;
   bool status = 0;

public:
    jdigital_c();
    ~jdigital_c();
    void setstatus();
    bool getstatus();
    QJsonObject openjfile(QFile &file);
    QJsonObject readjson(int i, QJsonObject &jsonobj);
    void saveval(jdigital *ptr, QJsonObject &jsonobj);
    void getdata(int nos, QFile &file, jdigital *ptr);
    //void writejson(QFile &file);
    void printjson(jdigital *ptr, int nos);

};
#endif // JDIGITAL_C_H
