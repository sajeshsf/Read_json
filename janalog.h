#ifndef janalog_H
#define janalog_H

#include <QString>

class janalog
{

private:
   int para_id;
   int channelno;
   QString legend;
   double scalefactor;
   double offset;
   QString unit;
   double upper_limit;
   double lower_limit;

public:
    janalog();
    //~janalog();
    janalog(const janalog &obj);
    void setpara_id(int i);
    void setchannelno(int i);
    void setlegend(QString i);
    void setscalefactor(double i);
    void setoffset(double i);
    void setunit(QString i);
    void setupper_limit(double i);
    void setlower_limit(double i);
    int getpara_id();
    int getchannelno();
    QString getlegend();
    double getscalefactor();
    double getoffset();
    QString getunit();
    double getupper_limit();
    double getlower_limit();
};

#endif // janalog_H
