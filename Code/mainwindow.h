#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPainter>
#include <QString>
#include <QFile>
#include <QMainWindow>
#include "graphicMeasurement.h"
#include "ploter.h"
#include "error.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
private slots:
    void on_loadFile_clicked();

    void on_infoShortOutput_cursorPositionChanged();

    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

    void on_zoomer_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QString filename;
    QFile file;
    GraphicMeasurement data;
    Ploter ploter;
    QRect windowForPlot;
    const int bordur = 40;
    int zoom;
    QList<Error> errorList;

    bool inGraphic(QPoint *p);
    void error(Error err);
    void error(QList<Error>errs);
    void printInfoShort();
    void setWindowForPlot();
};
#endif // MAINWINDOW_H
