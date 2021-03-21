#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H

#include <QWidget>
#include "mainwindow.h"

class GraphicWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GraphicWidget(QWidget *parent = nullptr);
    void setMainWindow(MainWindow *mw);
protected:
     void paintEvent(QPaintEvent *event);
private:
     MainWindow *mainWin;
signals:

};

#endif // GRAPHICWIDGET_H
