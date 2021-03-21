#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowForPlot();
    data.setErrorList(&errorList);
    ui->errors->setTextColor(Qt::red);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::error(Error err)
{
    if(err.errorNumber == 0)
        return;
    QString text = "error " + QString::number(err.errorNumber) + ": " + err.interp()+'\n';
    text += "in string " + QString::number(err.stringNumber) + ": " + err.str+"\n";
    ui->errors->setText(text);
}

void MainWindow::error(QList<Error>errs)
{
    QString text = "";
    foreach(Error err,errs)
    {
        text += "error " + QString::number(err.errorNumber) + ": " + err.interp()+'\n';
        text += "in string " + QString::number(err.stringNumber) + ": " + err.str+"\n";
    }
    ui->errors->setText(text);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter graphPainter(this);
    graphPainter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    ploter.setWindow(windowForPlot);
    ploter.set(&graphPainter,&data);
    graphPainter.setPen(Qt::green);
    ploter.drawScale(&graphPainter);
    graphPainter.setPen(Qt::black);
    data.draw(&graphPainter);
    ui->xMinLabel->setText("x: " + QString::number(ploter.getMinX()));
    ui->xMaxLabel->setText("x: " + QString::number(ploter.getMaxX()));
    ui->yMinLabel->setText("y: " + QString::number(ploter.getMinY()));
    ui->yMaxLabel->setText("y: " + QString::number(ploter.getMaxY()));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int z=1;
    switch (event->button())
    {
    case Qt::LeftButton: z=zoom;break;
    case Qt::RightButton: z=-zoom;break;
    }
    data.setZoom(z,data.mousePosition( event->pos() ).x());
    repaint();
}

void MainWindow::printInfoShort()
{
    QString text = data.getHead()->infoForPrint()
            + QString::number(data.numElems()) + " points loaded\n"
            + "x: ["+QString::number(ploter.getMinX())+";"+QString::number(ploter.getMaxX())+"]\n"
            + "y: ["+QString::number(ploter.getMinY())+";"+QString::number(ploter.getMaxY())+"]\n";
    ui->infoShortOutput->setText( text );
}

void MainWindow::setWindowForPlot()
{
    int x = bordur;
    int y = ui->yMaxLabel->pos().y() + ui->yMaxLabel->height() + bordur;
    int w = this->width()-x-bordur;
    int h = this->height()-y-bordur;
    windowForPlot.setRect(x,y,w,h);
    ui->yMinLabel->setGeometry(x+w/2,y+h,150,30);
    ui->yMaxLabel->setGeometry(x+w/2,y-30,150,30);
    ui->xMinLabel->setGeometry(x,y-30,150,30);
    ui->xMaxLabel->setGeometry(x+w-50-bordur,y-30,150,30);
    zoom = 2;
}

void MainWindow::on_loadFile_clicked()
{

    filename = QFileDialog::getOpenFileName(this, "Open Dialog", "", "*.ssd *.SSD");
    ui->errors->setText("");
    errorList.clear();
    file.setFileName(filename);
    file.open(QIODevice::ReadOnly);
    if(file.isOpen())
    {
        Error err = data.loadFile(&file);
        if(err.errorNumber)
        {
//            errorList.append(err);
        }
        file.close();
    }
    else
    {
        errorList.append(Error(1,0,""));
        error(errorList);
    }
    ploter.set(NULL,&data);
    printInfoShort();
    error(errorList);
    repaint();
}

void MainWindow::on_infoShortOutput_cursorPositionChanged()
{

}

void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    setWindowForPlot();
}

void MainWindow::on_zoomer_valueChanged(int arg1)
{
    zoom=arg1;
}

void MainWindow::on_pushButton_clicked()
{
    data.zoomOff();
    repaint();
}
