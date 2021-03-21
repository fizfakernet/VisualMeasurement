#ifndef PLOTER_H
#define PLOTER_H

#include <QPainter>
#include "graphicMeasurement.h"

class Ploter
{
public:
    Ploter();
    Ploter(QPainter *p,GraphicMeasurement *gr);
    void set(QPainter *p,GraphicMeasurement *gr);
    void setWindow(int x, int y, int x_, int y_);
    void setWindow(QRect rect);
    void drawScale(QPainter *p);
    qreal getMinX(){return minX;}
    qreal getMinY(){return minY;}
    qreal getMaxX(){return maxX;}
    qreal getMaxY(){return maxY;}

private:
    qreal minX,minY,maxX,maxY;//минимамальные и максимальные значения
    qreal ax,bx,ay,by;//парамантры масжабирования
    int x1,x2,y1,y2;//координаты окна рисования
    QPainter *painter;
    GraphicMeasurement *graphic;
    static QPointF wherePointInGraphic(QPoint p);
};

#endif // PLOTER_H
