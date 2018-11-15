#ifndef JANALOG_C_H
#define JANALOG_C_H

#include "janalog.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

class janalog_c
{

private:

   janalog *ptr;
   bool status = 0;

public:
    janalog_c();
    ~janalog_c();
    void setstatus();
    bool getstatus();
    QJsonObject openjfile(QFile &file);
    QJsonObject readjson(int i, QJsonObject &jsonobj);
    void saveval(janalog *ptr, QJsonObject &jsonobj);
    void getdata(int nos, QFile &file, janalog *ptr);
    //void writejson(QFile &file);
    void printjson(janalog *ptr, int nos);

};

#endif // JANALOG_C_H
