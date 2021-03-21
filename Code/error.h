#ifndef ERROR_H
#define ERROR_H

#include <QString>

class Error
{
public:
    Error();
    Error(int errNum,int strNum,QString str_);
    int errorNumber;
    int stringNumber;
    QString str;
    QString interp();
};

#endif // ERROR_H
