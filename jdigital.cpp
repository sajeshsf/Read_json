#include "jdigital.h"


jdigital::jdigital()
{
   para_id = 0 ;
}

jdigital::jdigital(const jdigital &obj )
{
    para_id = obj.para_id;
    channelno = obj.channelno;
    legend = obj.legend;
    lo_text = obj.lo_text;
    hi_text = obj.hi_text;
    safe_level = obj.safe_level;
}

void jdigital::setpara_id(int i)
{
    para_id = i;
}

void jdigital::setchannelno(int i)
{
    channelno = i;
}

void jdigital:: setlegend(QString i)
{
    legend = i;
}

void jdigital:: setlo_text(QString i)
{
    lo_text = i;
}

void jdigital:: sethi_text(QString i)
{
    hi_text = i;
}

void jdigital:: setsafe_level(bool i)
{
    safe_level = i;
}


int jdigital::getpara_id()
{
    return para_id;
}

int jdigital::getchannelno()
{
    return channelno;
}

QString jdigital:: getlegend()
{
    return legend;
}

QString jdigital:: getlo_text()
{
    return lo_text;
}

QString jdigital:: gethi_text()
{
    return hi_text;
}

bool jdigital:: getsafe_level()
{
    return safe_level;
}

