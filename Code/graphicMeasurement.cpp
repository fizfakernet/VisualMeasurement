#include <iostream>
#include "graphicMeasurement.h"
#include "QStringList"

GraphicMeasurement::GraphicMeasurement()
{
    ax = ay = 1;
    bx = by = 0;
    zoomOff();
    errorList = NULL;
}

void GraphicMeasurement::zoomOff()
{
    startNum = 0;
    finishNum = contener.size()-1;
    if(contener.size()>0)
    {
        startX = contener.begin()->x();
        finishX = contener.at(finishNum).x();
    }
}

QPolygonF *GraphicMeasurement::getPoints()
{
    onMonitor = contener.mid(startNum,finishNum-startNum);
    return &onMonitor;
}

void GraphicMeasurement::draw(QPainter *p)
{
    QPolygonF graphic;
    foreach( QPointF elem, contener.mid(startNum,finishNum-startNum) )
    {
        graphic << QPointF(elem.x()*ax+bx,elem.y()*ay+by);
    }
    p->drawPolyline(graphic);
}

int GraphicMeasurement::numElems()
{
   return contener.size();
}

Error GraphicMeasurement::loadFile(QFile *f)
{
    contener.clear();
    Error err;
    if (f==NULL) return Error(1,0,"");
    err = head.read(f);
    if(err.errorNumber != 0) {return err;}
    err = readBody(f);
    if(err.errorNumber != 0)
    {
    //    return err;
    }
    return err;
}

void GraphicMeasurement::scale(qreal sx, qreal sy)
{
    ax = sx;
    ay = sy;
}

void GraphicMeasurement::scale(qreal sx, qreal sy,qreal b_x, qreal b_y)
{
    scale(sx,sy);
    bx = b_x;
    by = b_y;
}

void GraphicMeasurement::setZoomInterval(qreal start, qreal finish)
{
    if(elementsInInterval() < 2)
    {
        zoomOff();
        return;
    }
    startNum = 0;
    finishNum = 1;
    startX = start;
    finishX = finish;
    foreach( QPointF elem, contener )
    {
        if (elem.x()<startX) startNum++;
        if (elem.x()<finishX) finishNum++;
        if ( startNum>=contener.size() )
        {
            startNum = contener.size() - 2;
            break;
        }
        if(finishNum>=contener.size())
        {
            finishNum = contener.size() - 1;
            break;
        }
    }
}

void GraphicMeasurement::setZoom(int zoom,qreal x)
{
    qreal interval;
    qreal k;//коэффициент увеличения интервала
    if(zoom < -1) k = -(qreal)zoom;
    if(zoom > 1) k = 1/(qreal)zoom;
    interval = (finishX - startX)*k;
    startX = qMax(x - interval*0.5,contener[0].x());
    finishX = startX + interval;
    if(finishX > contener[contener.size()-1].x())
    {
        finishX = contener[contener.size()-1].x();
        startX = finishX - interval;
    }
    setZoomInterval(startX, finishX);
}

int GraphicMeasurement::elementsInInterval()
{
    return contener.mid(startNum,finishNum-startNum).size();
}

Error GraphicMeasurement::readBody(QFile *f)
{
    if(f==NULL) return Error(1,0,"");

    Error err;
    QString st;
    int p;
    QStringList strNums;
    qreal x,y;
    bool ok1,ok2;

    for(p=1;!f->atEnd();p++)
    {
        st = f->readLine();
        strNums = st.trimmed().split(" ");
        if( strNums.size() == 2 )
        {
            x = strNums[0].toDouble(&ok1);
            y = strNums[1].toDouble(&ok2);
            if( ok1 && ok2)
            {
            contener.push_back(QPointF(x,y));
            }
            else
            {
                err.errorNumber = 202;
                err.stringNumber = p + head.getStringsInHead();
                err.str = st;
                if(errorList != NULL)
                    errorList->append( err);
            }
        }
        else
        {
            err.errorNumber = 201;
            err.stringNumber = p + head.getStringsInHead();
            err.str = st;
            if(errorList != NULL)
                errorList->append( err);
        }
    }
    zoomOff();
    return err;
}

QPointF GraphicMeasurement::mousePosition(QPoint winPoint)
{
    return QPointF(((qreal)winPoint.x()-bx)/ax,((qreal)winPoint.y()-by)/ay);
}
