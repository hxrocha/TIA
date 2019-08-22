#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ag.h"

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

void MainWindow::on_btnCalcular_clicked()
{




    int populacao[TAMPOP][TAMCROMO];
    int populacaoFilhos[TAMPOP][TAMCROMO];
    float avaliacoes[TAMPOP];
    int filho1[TAMCROMO],filho2[TAMCROMO];
    srand(time(NULL));
    iniciaPopulacao(populacao);
    imprimePopulacao(populacao);
    int ng =  ui->edGeracoes->text().toInt();
    for(int g=0;g<ng;g++){
        fazAvaliacoes(populacao,avaliacoes);
        int pmelhor = achamelhor(avaliacoes);
        copiaCromo(populacaoFilhos[0],populacao[pmelhor]);
        int i =1;
        while(i < TAMPOP ){
            int p1 = torneio(avaliacoes);
            int p2 = torneio(avaliacoes);
            if(rand()%100 < 85){
                cruzamento(populacao[p1],populacao[p2],filho1,filho2);
            }else{
                mutacao(populacao[p1],filho1);
                mutacao(populacao[p2],filho2);
            }
            copiaCromo(populacaoFilhos[i],filho1);
            i++;
            if(i<TAMPOP){
                copiaCromo(populacaoFilhos[i],filho2);
                i++;
            }
        }
        copiaPopulacao(populacao,populacaoFilhos);
    }
    fazAvaliacoes(populacao,avaliacoes);
    int pmelhor = achamelhor(avaliacoes);
    printf("\n");
    imprimeCromo(populacao[pmelhor]);
    printf("\nValor encontrado %f",avaliacoes[pmelhor]);
    int n = binarioParaDecimal(populacao[pmelhor]);
    float x = 10.0/1023 *n;
    float r = x*sin(x*x);
    //printf("\nValor do x %f",r);
    ui->edResposta->setText(QString::number(r));











}
