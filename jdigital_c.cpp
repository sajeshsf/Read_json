#include "jdigital_c.h"

jdigital_c::jdigital_c()
{
    ptr = nullptr;
}

jdigital_c:: ~jdigital_c()
{
    if(ptr != nullptr)
        delete ptr;
}

void jdigital_c::setstatus()
{
    status = 1;
}

bool jdigital_c:: getstatus()
{
    return status;
}

QJsonObject jdigital_c::openjfile(QFile &file)
{
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(file.error() != QFile::NoError)
       qDebug() << "error";
    QString config_file = file.readAll();
    if(config_file.isEmpty())
       qDebug() << "empty";
    QJsonParseError JsonParseError;
    QJsonDocument jsondoc = QJsonDocument::fromJson(config_file.toUtf8(), &JsonParseError);
    QJsonObject jsonobj = jsondoc.object();
    file.close();
    return jsonobj;
}

QJsonObject jdigital_c::readjson(int i, QJsonObject &jsonobj)
{
            QJsonArray jsonarr = jsonobj.value("jdigital").toArray();
            QJsonValue jsonval = jsonarr.at(i).toObject();
            QJsonObject jsonobj1 = jsonval.toObject();
            return jsonobj1;
}

void jdigital_c::saveval(jdigital *ptr, QJsonObject &jsonobj)
{
    if (jsonobj.contains("para_id") && jsonobj["para_id"].isDouble())
       ptr->setpara_id(jsonobj["para_id"].toInt());

    if (jsonobj.contains("channelno") && jsonobj["channelno"].isDouble())
       ptr->setchannelno(jsonobj["channelno"].toInt());

    if (jsonobj.contains("legend") && jsonobj["legend"].isString())
       ptr->setlegend(jsonobj["legend"].toString());

    if (jsonobj.contains("lo_text") && jsonobj["lo_text"].isString())
        ptr->setlo_text(jsonobj["lo_text"].toString());

    if (jsonobj.contains("hi_text") && jsonobj["hi_text"].isString())
         ptr->sethi_text(jsonobj["hi_text"].toString());

    if (jsonobj.contains("safe_level") && jsonobj["safe_level"].isBool())
        ptr->setsafe_level(jsonobj["safe_level"].toBool());

}

void jdigital_c::getdata(int nos, QFile &file, jdigital *ptr)
{
   // ptr = new jdigital[nos];
    QJsonObject jsonobj = openjfile(file);
    QJsonObject jsonobj1;
    if(jsonobj.contains("jdigital"))
    {
        int i=0;
        while (i < nos)
        {
            jsonobj1 = readjson(i, jsonobj);
            saveval(&ptr[i], jsonobj1);
            i++;

         }
     }
    else
        qDebug () << "Wrong File.";
}

/*void json::writejson(QFile &file)
{
    QJsonObject jsonobj;
    jsonobj["para_id"] = para_id;
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
   file.write(jsondoc.toJson());
    file.close();

}*/

void jdigital_c::printjson(jdigital *ptr, int nos)
{
    int i=0;
    if(this->getstatus())
    while(i < nos)
    {
        qDebug () << "*/.............................../*";
        qDebug () << "parameter_id : " << ptr[i].getpara_id();
        qDebug () << "Channel_No : " << ptr[i].getchannelno();
        qDebug () << "Legend : " << ptr[i].getlegend();
        qDebug () << "lo_text : " << ptr[i].getlo_text();
        qDebug () << "hi_text : " << ptr[i].gethi_text();
        qDebug () << "safe_level : " << ptr[i].getsafe_level();
        qDebug () << "*/.............................../*";
        i++;
    }
}


