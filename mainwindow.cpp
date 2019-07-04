#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QPointF>
#include <QVector>
#include <QGraphicsView>
#include <QGraphicsScene>

vector<struct ponto> vp;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString filename="C:\\Users\\hugo\\Documents\\pkmeans\\durudataset.txt";
    QFile inputFile(filename);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          struct ponto p;
          QString line = in.readLine();
          ui->dadostxt->append(line);
          p.x = line.toFloat();
          line = in.readLine();
          ui->dadostxt->append(line);
          p.y = line.toFloat();
          vp.push_back(p);

       }
       inputFile.close();

    }






}

void MainWindow::on_pushButton_2_clicked()
{

        // printf("(%f,%f)",vp.at(i).x,vp.at(i).y);

    plot.setTitle( "K-means" );
    plot.setCanvasBackground( Qt::white );
    plot.setAxisAutoScale(QwtPlot::xBottom,true);
    plot.setAxisAutoScale(QwtPlot::yLeft,true);
    plot.insertLegend( new QwtLegend() );
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->attach( &plot );



    QGraphicsView * view = new QGraphicsView();
    QGraphicsScene * scene = new QGraphicsScene();


    QVector <QPointF> pontos;
    for(int i=0;i<vp.size();i++)
           pontos.append(QPointF(vp.at(i).x,vp.at(i).y));

   for(int i=0;i<vp.size();i++)
           scene->addEllipse(pontos[i].x(), pontos[i].y(), 1, 1);

    view->setScene(scene);

/*
    QwtPlotCurve *curve2 = new QwtPlotCurve();
    curve2->setTitle( "Média" );
    curve2->setPen( Qt::red, 4 );
    QPolygonF points2;
    for(int i=0;i<nGeracoes;i++)
        points2 << QPointF(i,medias.at(i));


    curve2->setSamples( points2 );
    curve2->attach( &plot );
    */
    struct ponto c1;
    struct ponto c2;
    struct ponto pr1;

    c1.x = rand()%201/100.0;
    c1.y = rand()%201/100.0;
    c2.x = rand()%201/100.0;
    c2.y = rand()%201/100.0;
    pr1.x = (c1.x+c2.x)/2;
    pr1.y = (c1.y+c2.y)/2;

    float Q = (c1.y - c2.y)/(c1.x - c2.x);
    float b = c1.y -Q*c1.x;

    float Q2 = -1/Q;
    float b2 = pr1.y - Q2*pr1.x;
    struct ponto pe1,pe2;
    pe1.x = 0;
    pe1.y = Q2*pe1.x + b2;
    pe2.x = 2;
    pe2.y = Q2*pe2.x + b2;

    for(int i=0;i<vp.size();i++){

        if(Q2*vp.at(i).x+1*vp.at(i).y+b2 >=0)
            vp.at(i).c = 1;
        else
             vp.at(i).c = -1;

    }

    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setTitle( "Pontos" );
    curve->setPen( Qt::blue, 4 );

    QPolygonF points;
    for(int i=0;i<vp.size();i++)
        if(vp.at(i).c == 1)
          points << QPointF(vp.at(i).x,vp.at(i).y);

    curve->setSamples( points );
    curve->attach( &plot );

    QwtPlotCurve *curvev = new QwtPlotCurve();
    curvev->setTitle( "Pontos" );
    curvev->setPen( Qt::green, 4 );

   // QPolygonF points;
    points.clear();
    for(int i=0;i<vp.size();i++)
        if(vp.at(i).c == -1)
          points << QPointF(vp.at(i).x,vp.at(i).y);

    curvev->setSamples( points );
    curvev->attach( &plot );



    QwtPlotCurve *curve2 = new QwtPlotCurve();
    curve2->setTitle( "unindo centroide" );
    curve2->setPen( Qt::red, 4 );
    QPolygonF points2;
    points2 << QPointF(c1.x,c1.y);
    points2 << QPointF(c2.x,c2.y);
    curve2->setSamples( points2 );
    curve2->attach( &plot );

    QwtPlotCurve *curve3 = new QwtPlotCurve();
    curve3->setTitle( "Separa" );
    curve3->setPen( Qt::yellow, 4 );
    QPolygonF points3;
    points3<< QPointF(pe1.x,pe1.y);
    points3 << QPointF(pe2.x,pe2.y);
    curve3->setSamples( points3 );
    curve3->attach( &plot );












    plot.resize( 500, 500 );
    plot.replot();
    plot.show();

}
