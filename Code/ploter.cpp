#include "ploter.h"

Ploter::Ploter()
{
    x1 = x2 = y1 = y2 = 0;
}

Ploter::Ploter(QPainter *p,GraphicMeasurement *gr)
{
    Ploter();
    set(p, gr);
}

void Ploter::set(QPainter *p, GraphicMeasurement *gr)
{
    painter = p;
    graphic = gr;
    qreal x,y;

    if(p != 0)
    {
        if( (x1>=x2) || (y1>=y2) )
        {
            x1 = 0;
            y1 = 0;
            x2 = p->window().width();
            y2 = p->window().height();
        }
    }

    if(gr != NULL)
    {
        if( gr->numElems() > 0 )
        {
            minX = maxX = gr->getPoints()->first().x();
            minY = maxY = gr->getPoints()->first().y();
        }
        foreach(QPointF elem, *gr->getPoints())
        {
            x = elem.x();
            minX = qMin( minX , x);
            maxX = qMax( maxX , x);
            y = elem.y();
            minY = qMin(minY , y);
            maxY = qMax(maxY , y);
        }
        ax = (x2-x1) / (maxX - minX)  ;
        ay = (y2-y1) / (maxY - minY) ;
    }
    else return;
    gr->scale(ax,-ay,-minX*ax+x1,+minY*ay+y2);
}

void Ploter::setWindow(int x, int y, int x_, int y_)
{
    x1 = x; y1 = y; x2 = x_;y2 = y_;
}

void Ploter::setWindow(QRect rect)
{
    x1 = rect.x();
    y1 = rect.y();
    x2 = rect.x()+rect.width();
    y2 = rect.y()+rect.height();
}

void Ploter::drawScale(QPainter *p)
{
    p->drawRect(x1,y1,x2-x1,y2-y1);
}
