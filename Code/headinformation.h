#include <QPainter>
#include <QFile>
#include <QMap>
#include "error.h"

#ifndef HEADINFORMATION_H
#define HEADINFORMATION_H

class HeadInformation
{
public:
    HeadInformation(){};
    HeadInformation(QFile *f);
    Error read(QFile *f);// указатель оставляет после заголовка
    QString infoForPrint();

    QString organizationName;
    QString applicationVersion;
    QString measurementType;
    QString measurementStartTime;
    QMap<QString,QString> measurementParametrs;
    int getStringsInHead(){return stringsInHead;}
    void setErrorList(QList<Error> *errList){errorList = errList;}
    QList<Error> *getErrorList(){ return errorList;}
private:
    int parseString(QString str);
    int parseStringParametr(QString str);
    int stringsInHead;
    QList<Error> *errorList;
    Error setError(Error e){if(errorList != NULL) errorList->append(e);return e;};
};

#endif // HEADINFORMATION_H
