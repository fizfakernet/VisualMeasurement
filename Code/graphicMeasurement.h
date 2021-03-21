#include <QPolygonF>

#include <QPainter>
#include <QFile>
#include "headinformation.h"
#include "error.h"

#ifndef GRAPHICMEASUREMENT_H
#define GRAPHICMEASUREMENT_H

class GraphicMeasurement
{
public:
    GraphicMeasurement();

    QPolygonF *getPoints();
    void draw(QPainter *p);
    int numElems();
    Error loadFile(QFile *f);
    void scale(qreal sx,qreal sy);// установка параметров отображения координат по формуле x*sx+b_x
    void scale(qreal sx,qreal sy,qreal b_x, qreal b_y);// установка параметров отображения координат по формуле x*sx+b_x
    void zoomOff();
    void setZoomInterval(qreal start,qreal finish);
    void setZoom(int zoom,qreal x);// если zoom отрицательный, то уменьшаем
    QPointF mousePosition(QPoint);
    HeadInformation *getHead(){return &head;};
    void setErrorList(QList<Error> *errList){errorList = errList;head.setErrorList(errorList);}
    QList<Error> *getErrorList(){ return errorList;}
private:
    QPolygonF contener, onMonitor;
    HeadInformation head;
    qreal ax,ay,bx,by;
    qreal startX,finishX;
    int startNum,finishNum;
    QList<Error> *errorList;

    int elementsInInterval();
    Error readBody(QFile *f);
};

#endif // GRAPHICMEASUREMENT_H
