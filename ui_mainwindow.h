/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCustomPlot *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *chemForm;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *denForm;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lowXForm;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *highXForm;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *dkevForm;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *plotType;
    QPushButton *plotButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QLabel *pointEn;
    QLabel *label_12;
    QLabel *pointMfp;
    QLabel *messageOut;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_7;
    QTextBrowser *dataText;
    QTextBrowser *edgesText;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1117, 596);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 1091, 541));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        widget = new QCustomPlot(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(290, 20, 781, 481));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 262, 195));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        chemForm = new QLineEdit(layoutWidget);
        chemForm->setObjectName(QStringLiteral("chemForm"));

        horizontalLayout->addWidget(chemForm);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        denForm = new QLineEdit(layoutWidget);
        denForm->setObjectName(QStringLiteral("denForm"));

        horizontalLayout_2->addWidget(denForm);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lowXForm = new QLineEdit(layoutWidget);
        lowXForm->setObjectName(QStringLiteral("lowXForm"));

        horizontalLayout_3->addWidget(lowXForm);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        highXForm = new QLineEdit(layoutWidget);
        highXForm->setObjectName(QStringLiteral("highXForm"));

        horizontalLayout_4->addWidget(highXForm);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        dkevForm = new QLineEdit(layoutWidget);
        dkevForm->setObjectName(QStringLiteral("dkevForm"));

        horizontalLayout_5->addWidget(dkevForm);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        plotType = new QComboBox(layoutWidget);
        plotType->setObjectName(QStringLiteral("plotType"));

        horizontalLayout_6->addWidget(plotType);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        plotButton = new QPushButton(layoutWidget);
        plotButton->setObjectName(QStringLiteral("plotButton"));

        verticalLayout_2->addWidget(plotButton);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 390, 231, 34));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        pointEn = new QLabel(layoutWidget1);
        pointEn->setObjectName(QStringLiteral("pointEn"));

        gridLayout->addWidget(pointEn, 0, 1, 1, 1);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 1, 0, 1, 1);

        pointMfp = new QLabel(layoutWidget1);
        pointMfp->setObjectName(QStringLiteral("pointMfp"));

        gridLayout->addWidget(pointMfp, 1, 1, 1, 1);

        messageOut = new QLabel(tab);
        messageOut->setObjectName(QStringLiteral("messageOut"));
        messageOut->setGeometry(QRect(20, 450, 231, 51));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 1, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        dataText = new QTextBrowser(tab_2);
        dataText->setObjectName(QStringLiteral("dataText"));

        gridLayout_2->addWidget(dataText, 1, 1, 1, 1);

        edgesText = new QTextBrowser(tab_2);
        edgesText->setObjectName(QStringLiteral("edgesText"));

        gridLayout_2->addWidget(edgesText, 1, 0, 1, 1);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1117, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_3->setText(QApplication::translate("MainWindow", "Chemical Formula", 0));
        chemForm->setText(QApplication::translate("MainWindow", "Si", 0));
        label_4->setText(QApplication::translate("MainWindow", "Density (g/cm^3)", 0));
        denForm->setText(QApplication::translate("MainWindow", "-1", 0));
        label->setText(QApplication::translate("MainWindow", "Low X-ray Energy (keV):", 0));
        lowXForm->setText(QApplication::translate("MainWindow", "1", 0));
        label_2->setText(QApplication::translate("MainWindow", "High X-ray Energy (keV)", 0));
        highXForm->setText(QApplication::translate("MainWindow", "20", 0));
        label_5->setText(QApplication::translate("MainWindow", "Energy Steps ( keV)", 0));
        dkevForm->setText(QApplication::translate("MainWindow", "0.2", 0));
        label_6->setText(QApplication::translate("MainWindow", "Type of Plot", 0));
        plotType->clear();
        plotType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "mean free path", 0)
         << QApplication::translate("MainWindow", "mac", 0)
         << QApplication::translate("MainWindow", "meac", 0)
        );
        plotButton->setText(QApplication::translate("MainWindow", "Plot", 0));
        label_10->setText(QApplication::translate("MainWindow", "Energy(keV):", 0));
        pointEn->setText(QApplication::translate("MainWindow", "Browsed El", 0));
        label_12->setText(QApplication::translate("MainWindow", "mfp (um):", 0));
        pointMfp->setText(QApplication::translate("MainWindow", "Browsed MFP", 0));
        messageOut->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Plot", 0));
        label_8->setText(QApplication::translate("MainWindow", "Data", 0));
        label_7->setText(QApplication::translate("MainWindow", "Edges", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Export Data", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Data", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
