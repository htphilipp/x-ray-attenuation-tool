#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./qcustomplot.h"
#include "xmatformula.h"
#include "vector"
#include <sstream>
#include <QTextStream>
#include <cmath>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    std::string formula;
    XmatFormula    *matx;
    double dens;
    QVector< double>  datE;
    QVector< double>  data;
    int           toplot; //0=mfp 1=mac 2=meac
    ~MainWindow();

private slots:
    void on_plotButton_clicked();
    void showPlotCoords(QMouseEvent*);
    void on_plotType_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
