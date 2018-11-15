#include "janalog_c.h"

janalog_c::janalog_c()
{
    ptr = nullptr;
    status = 0;
}

janalog_c:: ~janalog_c()
{
    if(ptr != nullptr)
        delete ptr;
}

void janalog_c::setstatus()
{
    status = 1;
}

bool janalog_c:: getstatus()
{
    return status;
}

QJsonObject janalog_c::openjfile(QFile &file)
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

QJsonObject janalog_c::readjson(int i, QJsonObject &jsonobj)
{
            QJsonArray jsonarr = jsonobj.value("janalog").toArray();
            QJsonValue jsonval = jsonarr.at(i).toObject();
            QJsonObject jsonobj1 = jsonval.toObject();
            return jsonobj1;
}

void janalog_c::saveval(janalog *ptr, QJsonObject &jsonobj)
{
    if (jsonobj.contains("para_id") && jsonobj["para_id"].isDouble())
       ptr->setpara_id(jsonobj["para_id"].toInt());

    if (jsonobj.contains("channelno") && jsonobj["channelno"].isDouble())
       ptr->setchannelno(jsonobj["channelno"].toInt());

    if (jsonobj.contains("legend") && jsonobj["legend"].isString())
       ptr->setlegend(jsonobj["legend"].toString());

    if (jsonobj.contains("scalefactor") && jsonobj["scalefactor"].isDouble())
       ptr->setscalefactor(jsonobj["scalefactor"].toDouble());

    if (jsonobj.contains("offset") && jsonobj["offset"].isDouble())
        ptr->setoffset(jsonobj["offset"].toDouble());

    if (jsonobj.contains("unit") && jsonobj["unit"].isString())
        ptr->setunit(jsonobj["unit"].toString());

    if (jsonobj.contains("upper_limit") && jsonobj["upper_limit"].isDouble())
        ptr->setupper_limit(jsonobj["upper_limit"].toDouble());

    if (jsonobj.contains("lower_limit") && jsonobj["lower_limit"].isDouble())
         ptr->setlower_limit(jsonobj["lower_limit"].toDouble());
}

void janalog_c::getdata(int nos, QFile &file, janalog *ptr)
{
    QJsonObject jsonobj = openjfile(file);
    QJsonObject jsonobj1;
    if(jsonobj.contains("janalog"))
    {
        int i=0;
        while (i < nos)
        {
            jsonobj1 = readjson(i, jsonobj);
            saveval(&ptr[i], jsonobj1);
            i++;

         }
        this->setstatus();

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

void janalog_c::printjson(janalog *ptr, int nos)
{

    int i=0;
    if(this->getstatus())
    while(i < nos)
    {
        qDebug () << "*/.............................../*";
        qDebug () << "parameter_id : " << ptr[i].getpara_id();
        qDebug () << "Channel_No : " << ptr[i].getchannelno();
        qDebug () << "Legend : " << ptr[i].getlegend();
        qDebug () << "Scalefactor : " << ptr[i].getscalefactor();
        qDebug () << "Offset : " << ptr[i].getoffset();
        qDebug () << "Unit : " << ptr[i].getunit();
        qDebug () << "Lower_limit : " << ptr[i].getlower_limit();
        qDebug () << "Upper_limit : " << ptr[i].getupper_limit();
        qDebug () << "*/.............................../*";
        i++;
    }
}
