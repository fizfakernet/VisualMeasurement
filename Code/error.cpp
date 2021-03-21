#include "error.h"

Error::Error()
{
    errorNumber = 0;
    stringNumber = -1;
    str = "";
}

Error::Error(int errNum,int strNum,QString str_)
{
    errorNumber = errNum;
    stringNumber = strNum;
    str = str;
}

QString Error::interp()
{
    switch(errorNumber)
    {
    case 0: return "ошибок нет";break;
    case 1: return "ошибка при открытии файла";break;
    case 101: return "неверный формат заголовка";break;
    case 201: return "неверное количество чисел в строке тела данных";break;
    case 202: return "неверно задано число";break;
    case 301: return "внутреняя ошибка программы";break;
    default: return "неизветсная ошибка";break;
    }
}
