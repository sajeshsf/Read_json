#ifndef JDIGITAL_H
#define JDIGITAL_H

#include <QString>

class jdigital
{

private:
   int para_id;
   int channelno;
   QString legend;
   QString lo_text;
   QString hi_text;
   bool safe_level;

public:
    jdigital();
    //~jdigital();
    jdigital(const jdigital &obj);
    void setpara_id(int i);
    void setchannelno(int i);
    void setlegend(QString i);
    void setlo_text(QString i);
    void sethi_text(QString i);
    void setsafe_level(bool i);

    int getpara_id();
    int getchannelno();
    QString getlegend();
    QString getlo_text();
    QString gethi_text();
    bool getsafe_level();
};

#endif // JDIGITAL_H
