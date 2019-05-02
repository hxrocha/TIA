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
        struct cidade capitais[27] = {{"Aracaju",0},{"Belem",1},{"Belo Horizonte",2},{"Boa Vista",3},{"Brasilia",4},{"Campo Grande",5},{"Cuiaba",6},{"Curitiba",7},{"Florianopolis",8},{"Fortaleza",9},{"Goiania",10},{"Joao Pessoa",11},{"Macapa",12},{"Maceio",13},{"Manaus",14},{"Natal",15},{"Palmas",16},{"Porto Alegre",17},{"Porto Velho",18},{"Recife",19},{"Rio Branco",20},{"Rio de Janeiro",21},{"Salvador",22},{"Sao Luis",23},{"Sao Paulo",24},{"Teresina",25},{"Vitoria",26}};
        struct cidade populacao[TAMPOPULACAO][TAMCROMOSSOMO];
        struct cidade populacaoFilhos[TAMPOPULACAO][TAMCROMOSSOMO];
        float avaliacoes[TAMPOPULACAO];
        struct cidade filho1[TAMCROMOSSOMO],filho2[TAMCROMOSSOMO];
        srand(time(NULL));
        int nGeracoes,nCruzamento,nMutacao;
        nGeracoes = ui->lineEditGeracao->text().toInt();
        nCruzamento = ui->lineEditCruzamento->text().toInt();
        nMutacao = ui->lineEditMutacao->text().toInt();
        int i;
        int pMelhor;
        float media;
        iniciaPopulacao(populacao,capitais);
        float melhores[nGeracoes];
        float medias[nGeracoes];
        //imprimeCodPopulacao(populacao);

        for(int g=0;g<nGeracoes;g++){
            fazAvaliacoes(populacao,avaliacoes);
            melhores[g] = achaMelhor(avaliacoes);
            medias[g] = mediaDasAvaliacoes(avaliacoes);
        i=0;
        do{
            int pai1 = torneio(avaliacoes,3);
            int pai2 = torneio(avaliacoes,3);
            if(rand()%(nCruzamento+nMutacao) <nCruzamento){
                cruzamento(populacao[pai1],populacao[pai2],filho1,filho2);
            }else{
                mutacao(populacao[pai1],filho1);
                mutacao(populacao[pai2],filho2);
            }
            copiaCromossomo(populacaoFilhos[i],filho1);
            i++;
            if(i<TAMPOPULACAO){
                copiaCromossomo(populacaoFilhos[i],filho2);
                i++;
            }
        }while(i<TAMPOPULACAO);
        copiaPopulacao(populacao,populacaoFilhos);

        }
        fazAvaliacoes(populacao,avaliacoes);
        pMelhor = achaMelhor(avaliacoes);
        imprimeCromo(populacao[pMelhor]);
        printf("\n A distancia percorrida foi de %.2f",
              avaliacoes[pMelhor]);

}

void MainWindow::on_lineEditCruzamento_editingFinished()
{
    int x = ui->lineEditCruzamento->text().toInt();
    if(x > 100){
          ui->lineEditMutacao->setText("0");
          ui->lineEditCruzamento->setText("100");
          x = 100;
    }
    if(x < 0){
         ui->lineEditCruzamento->setText("0");
          ui->lineEditMutacao->setText("100");
          x = 0;
    }

    ui->lineEditMutacao->setText( QString::number(100-x));
}
