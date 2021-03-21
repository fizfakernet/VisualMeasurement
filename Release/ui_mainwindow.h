/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loadFile;
    QTextEdit *infoShortOutput;
    QSpinBox *zoomer;
    QLabel *xMinLabel;
    QLabel *xMaxLabel;
    QLabel *yMaxLabel;
    QLabel *yMinLabel;
    QPushButton *pushButton;
    QTextEdit *errors;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(968, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loadFile = new QPushButton(centralwidget);
        loadFile->setObjectName(QString::fromUtf8("loadFile"));
        loadFile->setGeometry(QRect(30, 20, 75, 23));
        infoShortOutput = new QTextEdit(centralwidget);
        infoShortOutput->setObjectName(QString::fromUtf8("infoShortOutput"));
        infoShortOutput->setGeometry(QRect(290, 10, 661, 81));
        infoShortOutput->setReadOnly(true);
        zoomer = new QSpinBox(centralwidget);
        zoomer->setObjectName(QString::fromUtf8("zoomer"));
        zoomer->setGeometry(QRect(180, 50, 42, 22));
        zoomer->setMinimum(2);
        xMinLabel = new QLabel(centralwidget);
        xMinLabel->setObjectName(QString::fromUtf8("xMinLabel"));
        xMinLabel->setGeometry(QRect(50, 540, 47, 13));
        xMaxLabel = new QLabel(centralwidget);
        xMaxLabel->setObjectName(QString::fromUtf8("xMaxLabel"));
        xMaxLabel->setGeometry(QRect(920, 540, 47, 13));
        yMaxLabel = new QLabel(centralwidget);
        yMaxLabel->setObjectName(QString::fromUtf8("yMaxLabel"));
        yMaxLabel->setGeometry(QRect(40, 110, 47, 13));
        yMinLabel = new QLabel(centralwidget);
        yMinLabel->setObjectName(QString::fromUtf8("yMinLabel"));
        yMinLabel->setGeometry(QRect(40, 490, 47, 13));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 50, 51, 23));
        errors = new QTextEdit(centralwidget);
        errors->setObjectName(QString::fromUtf8("errors"));
        errors->setGeometry(QRect(290, 90, 661, 81));
        errors->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 968, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loadFile->setText(QCoreApplication::translate("MainWindow", "loadFile", nullptr));
        xMinLabel->setText(QCoreApplication::translate("MainWindow", "xMin", nullptr));
        xMaxLabel->setText(QCoreApplication::translate("MainWindow", "xMax", nullptr));
        yMaxLabel->setText(QCoreApplication::translate("MainWindow", "yMax", nullptr));
        yMinLabel->setText(QCoreApplication::translate("MainWindow", "yMin", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "zoom off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
