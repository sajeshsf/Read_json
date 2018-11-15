#include "janalog.h"

janalog::janalog()
{
   para_id = 0 ;
}

janalog::janalog(const janalog &obj )
{
    para_id = obj.para_id;
    channelno = obj.channelno;
    legend = obj.legend;
    scalefactor = obj.scalefactor;
    offset = obj.offset;
    unit = obj.unit;
    upper_limit = obj.upper_limit;
    lower_limit = obj.lower_limit;
}

void janalog::setpara_id(int i)
{
para_id=i;
}

void janalog::setchannelno(int i)
{
    channelno = i;
}

void janalog:: setlegend(QString i)
{
    legend = i;
}

void janalog:: setscalefactor(double i)
{
    scalefactor = i;
}

void janalog:: setoffset(double i)
{
    offset = i;
}

void janalog:: setunit(QString i)
{
    unit = i;
}

void janalog:: setupper_limit(double i)
{
    upper_limit = i;
}

void janalog:: setlower_limit(double i)
{
    lower_limit = i;
}

int janalog::getpara_id()
{
    return para_id;
}

int janalog::getchannelno()
{
    return channelno;
}

QString janalog:: getlegend()
{
    return legend;
}

double janalog:: getscalefactor()
{
    return scalefactor;
}

double janalog:: getoffset()
{
    return offset;
}

QString janalog:: getunit()
{
    return unit;
}

double janalog:: getupper_limit()
{
    return upper_limit;
}

double janalog:: getlower_limit()
{
    return lower_limit;
}
