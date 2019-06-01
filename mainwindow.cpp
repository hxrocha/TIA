#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colonia.h"

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

    int i,j,w;
    float somatorio;
    float n[TAM][TAM];
    float p[TAM][TAM];
    float feromonio[TAM][TAM];
    srand(time(NULL));
    vector <int> Sk,S;
    float L = FLT_MAX;
    int K = ui->edFormigas->text().toInt();
    float vetDistancias[K];
    vector<int> vetCaminhos[K];
    float caminhos[TAM][TAM]={
        {-1,5.0,3.1,-1,-1,5.2,-1},
        {5.0,-1,4.9,-1,-1,-1,5.2},
        {3.1,4.9,-1,-1,6,3.2,3},
        {-1,-1,-1,-1,5.5,-1,4.8},
        {-1,-1,6,5.5,-1,4.7,-1},
        {5.2,-1,3.2,-1,4.7,-1,-1},
        {-1,5.2,3,4.8,-1,-1,-1}};

    geraMatrizN(caminhos,n);
    geraMatrizFeromonio(feromonio);
    int g;
    int iteracoes = ui->edIteracoes->text().toInt();
    for(g = 0;g<iteracoes;g++){
        geraMatrizP(caminhos,feromonio,n,p);
        int r ;
        for(i=0;i<K;i++){
            do{
            Sk.clear();
            Sk.push_back(0);
            int laco =0;
            do{
                r = sorteio(p[Sk.back()]);
                if(eInedita(r,Sk)){
                    Sk.push_back(r);
                    laco = 0;
                }
                else
                    laco++;
            }while((r !=3) && (laco <= 10));
        }while(r!=3);

        float Lk = calculaDistancia(Sk,caminhos);

        if(Lk < L ){
            L =Lk;
            S = Sk;
        }
        vetDistancias[i] = Lk;
        vetCaminhos[i]=Sk;
        }
        atualizaFeromonio(feromonio,K,vetDistancias,vetCaminhos);
    }

    QString v;

    for(i=0;i<S.size();i++)
        v += " " + QString::number(S.at(i));
    ui->edResposta->setText(v);

}
