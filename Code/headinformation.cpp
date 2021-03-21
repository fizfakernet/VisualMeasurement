#include "headinformation.h"
#include <QPair>

HeadInformation::HeadInformation(QFile *f)
{
    read(f);
}

int HeadInformation::parseString(QString str)
{
    QString notSpace = str.trimmed();
    if(notSpace.length()<1) return 0;
    if( ((notSpace[0]>='0') && (notSpace[0]<='9')) || (notSpace[0] == '-') ) return -1;
    if( str[0] == '#' ) return -2;
    if(notSpace.length()>0)        return -101;
    return 0;
}

void delSharp(QString *str)
{
    int i;
    for(i=0;i<str->size();i++)
    {
        QChar ch = str->at(i);
        if( (ch != '#') && (ch != ' ') && (ch != '\t') )
        {
            break;
        }
    }
    str->remove(0,i);
}

Error HeadInformation::read(QFile *f)
{
    Error err;
    if(f==NULL) return setError(Error(1,0,""));
    bool repeadEnd = false;
    QString st;
    int p,numHeaderLine=0;

    for(p=1;(!f->atEnd())&&(!repeadEnd);p++)
    {
        st = f->readLine();
        switch(parseString(st))
        {
        case -2: // заголовок
            delSharp(&st);
            switch(numHeaderLine)
            {
            case 0:{
                QStringList qst = st.trimmed().split(',');
                if(qst.size() >= 2)
                {
                    organizationName = qst[0];
                    applicationVersion = qst[1];
                }
                else
                {
                    err.errorNumber = 101;
                    err.stringNumber = p;
                    err.str = st;
                    if(errorList != NULL)
                        errorList->append( err );
                    return err;
                }
                numHeaderLine++;
                break;}
            case 1: measurementType = st;break;
            case 2: measurementStartTime = st;break;
            default: parseStringParametr(st);break;
            }

            break;
        case -1: // тело
            repeadEnd = true;
            break;
        case -101:
            err.errorNumber = 101;
            err.stringNumber = p;
            err.str = st;
            if(errorList != NULL)
                errorList->append( err );

            break;
        }
    }
    f->close();
    f->open(QIODevice::ReadOnly);
    for(int i=2;i<p;i++)
        f->readLine();
    stringsInHead = p;
    return err;
}

bool isParamName(QString word)
{
    int tail = word.size()-1;
    if (tail < 1) return false;
    return (word[word.size()-1] == ':');
}

int HeadInformation::parseStringParametr(QString str)
{
    QStringList words = str.trimmed().split(" ");
    QString key = "",value="";
    foreach(QString word, words)
    {
        if(isParamName(word))
        {
            if(!key.isEmpty()) measurementParametrs.insert(key,value);
            key = word;
            value = "";
        }
        else
        {
            if(!value.isEmpty()) value.append( " ");
            value.append( word);
        }
    }
    return 0;
}

QString HeadInformation::infoForPrint()
{
    QString text("organization: " + organizationName + "\n");
    text += "applicationVersion: " + applicationVersion + "\n"
        + "measurement: " + measurementType + "\n"
        + "StartTime: " + measurementStartTime + "\n";

    foreach (QString key, measurementParametrs.keys())

    {

      QString value=measurementParametrs.value(key);
    }
    return text;
}
