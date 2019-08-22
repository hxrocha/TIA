#ifndef AG_H
#define AG_H
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAMPOP 100
#define TAMCROMO 10

void iniciaPopulacao(int populacao[TAMPOP][TAMCROMO]){
    for(int i=0;i<TAMPOP;i++)
        for(int j=0;j<TAMCROMO;j++)
            populacao[i][j]=rand()%2;
}
void imprimeCromo(int *cromo){
    printf("\n");
    for(int i=0;i<TAMCROMO;i++)
        printf("%d ",cromo[i]);
}
void imprimePopulacao(int populacao[TAMPOP][TAMCROMO]){
    for(int i=0;i<TAMPOP;i++)
        imprimeCromo(populacao[i]);
}

int binarioParaDecimal(int *cromo){
    int somatorio = 0;
    int elevado = 9;
    for(int i=0;i<TAMCROMO;i++){
        somatorio += cromo[i]*pow(2.0,elevado--);
    }
    return(somatorio);
}
void fazAvaliacoes(int populacao[TAMPOP][TAMCROMO],float *avaliacoes){
    int n;
    for(int i=0;i<TAMPOP;i++){
        n = binarioParaDecimal(populacao[i]);
        float x = 10.0/1023 *n;
        avaliacoes[i] = x*sin(x*x)+10;
    }
}



int torneio(float *avaliacoes){
    int melhor = rand()%TAMPOP;
    for(int i = 1;i<3;i++){
        int e = rand()%TAMPOP;
        if(avaliacoes[e] > avaliacoes[melhor])
            melhor = e;
    }
    return(melhor);
}

int achamelhor(float *avaliacoes){
    int melhor = 0;
    for(int i = 1;i<TAMPOP;i++){
        if(avaliacoes[i] > avaliacoes[melhor])
            melhor = i;
    }
    return(melhor);
}

void cruzamento(int *pai1,int *pai2,int *filho1,int *filho2){
    int pc = rand()%(TAMCROMO-1) +1;
    for(int i=0;i<pc;i++){
        filho1[i] = pai1[i];
        filho2[i] = pai2[i];
    }
    for(int i=pc;i<TAMCROMO;i++){
        filho1[i]=pai2[i];
        filho2[i]=pai1[i];
    }
}

void mutacao(int *pai,int *filho){
    for(int i=0;i<TAMCROMO;i++){
        filho[i] = pai[i];
    }
    int pm = rand()%TAMCROMO;
//	printf("\n ponto de mutacao %d",pm);
    if(filho[pm]==0)
        filho[pm]=1;
    else
        filho[pm]=0;
}

void copiaCromo(int *dest,int *origem){
    for(int i=0;i<TAMCROMO;i++)
        dest[i]=origem[i];
}

void copiaPopulacao(int populacao[TAMPOP][TAMCROMO],int populacaoFilhos[TAMPOP][TAMCROMO]){
    for(int i=0;i<TAMPOP;i++)
        copiaCromo(populacao[i],populacaoFilhos[i]);
}








#endif // AG_H
