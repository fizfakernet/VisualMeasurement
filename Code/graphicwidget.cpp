#include "graphicwidget.h"

GraphicWidget::GraphicWidget(QWidget *parent) : QWidget(parent)
{
    mainWin = NULL;
}

void GraphicWidget::setMainWindow(MainWindow *mw)
{
    mainWin = mw;
}

void GraphicWidget::paintEvent(QPaintEvent *event)
{
    QPainter graphPainter(this);
    graphPainter.begin(ui->graphic_widget);
    graphPainter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
//    graphPainter.setWindow(10,100,300,400);

    mainWin->ploter.set(&graphPainter,&mainWin->data);
    mainWin->data.draw(&graphPainter);
}
