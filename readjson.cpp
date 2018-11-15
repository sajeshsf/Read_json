#include "readjson.h"

janalog* analog_json(QFile &file, int nos)
{
    qDebug() << "Reading analog config";
    janalog_c* obj = new janalog_c();
    janalog *ptr = new janalog[nos];
    if (file.exists())
    {
        qDebug() << "File exists";
        obj->getdata(nos, file, ptr);
        obj->printjson(ptr, nos);
        delete obj;
    }
    else
         qDebug () << "File doesnt exixts.";
     return ptr;
}

jdigital* digital_json(QFile &file, int nos)
{
    qDebug() << "Reading digital config";
    jdigital_c* obj = new jdigital_c();
    jdigital *ptr = new jdigital[nos];
    if (file.exists())
    {
        qDebug() << "File exists";
        obj->getdata(nos, file, ptr);
        obj->printjson(ptr, nos);
        delete obj;
    }
   else
        qDebug () << "File doesnt exixts.";
    return ptr;
}
