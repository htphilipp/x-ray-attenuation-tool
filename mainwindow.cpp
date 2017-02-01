#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->tabWidget);
    this->setWindowTitle("X-ray mean free path calculator");
    formula.assign("Si");
    matx=new XmatFormula(formula);

    ui->widget->addGraph();
    ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    ui->widget->addGraph();
    ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));

   // connect(ui->widget,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(showPlotCoords(QMouseEvent*)));

    connect(ui->widget,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(showPlotCoords(QMouseEvent*)));

    ui->tab->setAutoFillBackground(true);
    formula.assign("Si");

    toplot=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_plotButton_clicked()
{
    QString chemForm,enhighs,enlows,des,densq;
    std::stringstream datxt;

    //double enlow,enhigh,enin,de;
    double enlow,enhigh,de;
    int ndiv;
    XmatFormula *xtemp;
    double en;

    //reading text
    chemForm=ui->chemForm->text();
    enhighs=ui->highXForm->text();
    enlows=ui->lowXForm->text();
    des=ui->dkevForm->text();
    densq=ui->denForm->text();

    dens = densq.toDouble();


    enhigh=enhighs.toDouble();
    enlow=enlows.toDouble();
    de=des.toDouble();

    ndiv = ((enhigh-enlow)/de);

    //if(formula!=chemForm.toStdString())
    //{

    try
    {
        if(dens<=0)
        {
            xtemp = new XmatFormula(chemForm.toStdString());
        }
        else
        {
           xtemp = new XmatFormula(chemForm.toStdString(),dens);
        }

        delete matx;
        matx = xtemp;
        matx->mfpunit("um");
    //}

    datE.clear();
    data.clear();
   // datxt.device()->reset();  //trying to clear qTextStream Buffer.
    datxt.clear();
    ui->dataText->clear();
    ui->messageOut->setText(QString(""));
    }
    catch(const char* msg)
    {
       //ui->messageOut->setText(QString::QString(msg));
        ui->messageOut->setText(QString(msg));
    }

    datxt<<"keV, \t mac, \t meac, \t mfp(um)"<<std::endl;

    for(auto i=0;i<=ndiv;i++)
    {
        en = i*de+enlow;
        datE.push_back(en);
        switch(toplot)
        {
            case 0:
                data.push_back(matx->mfp(en));
                break;
            case 1:
                data.push_back(matx->mac(en));
                break;
            case 2:
                data.push_back(matx->meac(en));
                break;
        }
        datxt<<en<<",\t"<<matx->mac(en)<<",\t"<<matx->meac(en)<<",\t"<<matx->mfp(en)<<std::endl;
        //ui->dataText->append(QString::number(en));
        //ui->dataText->append(QString(" , "));

    }
    ui->dataText->append(QString::fromStdString(datxt.str()));
    ui->edgesText->setText("Energies of Edges (keV) ");
    for(double j:matx->edges())
    {
        ui->edgesText->append(QString::number(j));
        //ui->textBrowser->append(QString("\n "));
    }

    ui->widget->graph(0)->setData(datE,data);

    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->xAxis->grid()->setSubGridVisible(true);


    ui->widget->yAxis->setScaleType(QCPAxis::stLogarithmic);


    ui->widget->graph(0)->rescaleAxes();
    ui->widget->graph(0)->visible();

    ui->widget->replot();

}

void MainWindow::showPlotCoords(QMouseEvent *event)
{
    ui->messageOut->setText(QString(""));
    //ui->messageOut->setText(QString::QString(""));
    double p = ui->widget->xAxis->pixelToCoord(event->pos().x());

    QVector<double> enx(1), mfpy(1);

    try
    {
            enx[0]=p;
            switch(toplot)
            {
                case 0:
                    mfpy[0]=matx->mfp(p);
                    ui->widget->graph(1)->setData(enx,mfpy);
                    ui->widget->replot();
                    ui->pointEn->setText(QString::number( p));
                    ui->pointMfp->setText(QString::number( matx->mfp(p)));
                    break;
                case 1:
                    mfpy[0]=matx->mac(p);
                    ui->widget->graph(1)->setData(enx,mfpy);
                    ui->widget->replot();
                    ui->pointEn->setText(QString::number( p));
                    ui->pointMfp->setText(QString::number( matx->mac(p)));
                    break;
                case 2:
                    mfpy[0]=matx->meac(p);
                    ui->widget->graph(1)->setData(enx,mfpy);
                    ui->widget->replot();
                    ui->pointEn->setText(QString::number( p));
                    ui->pointMfp->setText(QString::number( matx->meac(p)));
                    break;
            }


            //ui->edgesText->append(QString::number(p));
    }
    catch(const char* msg)
    {
        //ui->messageOut->setText(QString::QString(msg));
         ui->messageOut->setText(QString(msg));
    }
}


void MainWindow::on_plotType_currentIndexChanged(int index)
{
    //ui->messageOut->setText(QString::number(index));
    switch(index)
    {
        case 0:
            ui->label_12->setText("mfp (um):");
            ui->pointEn->setText(QString::number( 0));
            ui->pointMfp->setText(QString::number( 0));
            break;
        case 1:
            ui->label_12->setText("mac (cm^2/g):");
            ui->pointEn->setText(QString::number( 0));
            ui->pointMfp->setText(QString::number( 0));
            break;
        case 2:
            ui->label_12->setText("meac (cm^2/g):");
            ui->pointEn->setText(QString::number( 0));
            ui->pointMfp->setText(QString::number( 0));
            break;
    }
    toplot = index;


}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog filedialog;
    filedialog.setFileMode(QFileDialog::AnyFile);
    try
    {
    QString fileName = filedialog.getSaveFileName(NULL, "Create New File","","");
    QFile   *file;

    file = new QFile(fileName);
    file->open(QIODevice::WriteOnly);
    QTextStream stream(file);
    stream << ui->dataText->toPlainText();
    file->flush();
    file->close();

    delete file;
    }
    catch(const char* msg)
    {
        //ui->messageOut->setText(QString::QString(msg));
         ui->messageOut->setText(QString(msg));
    }

//    if (file.open(QIODevice::ReadWrite)) {
//        QTextStream stream(&file);
//        stream << ui->dataText->toPlainText();
//        file.flush();
//        file.close();
//    }
//    else {
//        QMessageBox::critical(this, tr("Error"), tr("file open problem"));
//        return;
//    }


}
