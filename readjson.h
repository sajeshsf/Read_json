#ifndef READJSON_H
#define READJSON_H

#include "janalog_c.h"
#include "jdigital_c.h"

#include <QFile>
#include <QDebug>

janalog *analog_json(QFile &file, int nos);

jdigital *digital_json(QFile &file, int nos);

#endif // READJSON_H
