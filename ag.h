#ifndef AG_H
#define AG_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define TAMCROMOSSOMO 27
#define TAMPOPULACAO 1500

struct cidade{
    char nome[20];
    int numero;
};

int distancias[27][27] = {0,1641,1248,3022,1292,2155,2121,2061,2207,815,1461,486,1967,201,2673,604,1235,2580,2946,398,3359,1482,277,1226,1731,903,1102,1641,0,2111,1432,1592,2212,1778,2665,2904,1133,1693,1636,329,1680,1292,1550,973,3188,1886,1676,2333,2450,1687,481,2463,750,2275,1248,2111,0,3117,624,1118,1372,820,973,1893,666,1726,2349,1439,2556,1831,1178,1341,2477,1639,2786,339,964,1932,489,1652,378,3022,1432,3117,0,2496,2667,2107,3370,3620,2562,2503,3067,1110,3089,661,2983,1988,3785,1335,3103,1626,3428,3009,1913,3300,2169,3394,1292,1592,624,2496,0,878,873,1081,1314,1687,173,1716,1791,1485,1932,1775,620,1619,1900,1657,2246,933,1060,1524,873,1313,947,2155,2212,1118,2667,878,0,559,780,1007,2547,705,2593,2309,2352,2013,2654,1320,1119,1634,2530,1827,1212,1905,2284,894,2132,1490,2121,1778,1372,2107,873,559,0,1302,1543,2329,740,2495,1822,2302,1453,2524,1029,1679,1137,2452,1414,1575,1915,1942,1326,1862,1745,2061,2665,820,3370,1081,780,1302,0,251,2670,972,2545,2836,2259,2734,2645,1693,546,2412,2459,2601,675,1784,2599,338,2362,1076,2207,2904,973,3620,1314,1007,1543,251,0,2857,1215,2693,3082,2402,2981,2802,1931,376,2641,2603,2809,748,1930,2821,489,2573,1160,815,1133,1893,2562,1687,2547,2329,2670,2857,0,1854,555,1451,730,2383,435,1300,3213,2855,629,3300,2190,1028,652,2368,495,1855,1461,1693,666,2503,173,705,740,972,1215,1854,0,1889,1868,1656,1912,1948,724,1497,1813,1829,2138,936,1225,1662,810,1467,1022,486,1636,1726,3067,1716,2593,2495,2545,2693,555,1889,0,1964,299,2819,151,1521,3066,3200,104,3632,1968,763,1162,2216,905,1581,1967,329,2349,1110,1791,2309,1822,2836,3082,1451,1868,1964,0,2009,1054,1874,1177,3341,1724,2005,2159,2687,2000,803,2664,1079,2545,201,1680,1439,3089,1485,2352,2302,2259,2402,730,1656,299,2009,0,2778,434,1383,2775,3090,202,3510,1671,475,1234,1928,929,1282,2673,1292,2556,661,1932,2013,1453,2734,2981,2383,1912,2819,1054,2778,0,2765,1509,3132,761,2833,1149,2849,2605,1746,2689,1921,2865,604,1550,1831,2983,1775,2654,2524,2645,2802,435,1948,151,1874,434,2765,0,1527,3172,3179,253,3616,2085,875,1071,2320,843,1706,1235,973,1178,1988,620,1320,1029,1693,1931,1300,724,1521,1177,1383,1509,1527,0,2222,1711,1498,2127,1512,1114,964,1493,835,1413,2580,3188,1341,3785,1619,1119,1679,546,376,3213,1497,3066,3341,2775,3132,3172,2222,0,2706,2977,2814,1123,2303,3142,852,2909,1536,2946,1886,2477,1335,1900,1634,1137,2412,2641,2855,1813,3200,1724,3090,761,3179,1711,2706,0,3190,449,2707,2808,2274,2463,2362,2835,398,1676,1639,3103,1657,2530,2452,2459,2603,629,1829,104,2005,202,2833,253,1498,2977,3190,0,3618,1874,675,1209,2128,934,1483,3359,2333,2786,1626,2246,1827,1414,2601,2809,3300,2138,3632,2159,3510,1149,3616,2127,2814,449,3618,0,2982,3206,2726,2704,2806,3156,1482,2450,339,3428,933,1212,1575,675,748,2190,936,1968,2687,1671,2849,2085,1512,1123,2707,1874,2982,0,1209,2266,357,1979,412,277,1687,964,3009,1060,1905,1915,1784,1930,1028,1225,763,2000,475,2605,875,1114,2303,2808,675,3206,1209,0,1323,1453,994,839,1226,481,1932,1913,1524,2284,1942,2599,2821,652,1662,1162,803,1234,1746,1071,964,3142,2274,1209,2726,2266,1323,0,2348,329,2023,1731,2463,489,3300,873,894,1326,338,489,2368,810,2216,2664,1928,2689,2320,1493,852,2463,2128,2704,357,1453,2348,0,2091,741,903,750,1652,2169,1313,2132,1862,2362,2573,495,1467,905,1079,929,1921,843,835,2909,2362,934,2806,1979,994,329,2091,0,1713,1102,2275,378,3394,947,1490,1745,1076,1160,1855,1022,1581,2545,1282,2865,1706,1413,1536,2835,1483,3156,412,839,2023,741,1713,0};

void copiaCromossomo(struct cidade *destino,struct cidade *origem){
    for(int i=0;i<TAMCROMOSSOMO;i++)
        destino[i]=origem[i];
}
void embaralhaCromossomo(struct cidade *capitais){
    struct cidade aux;
    int pi,pj;
    for(int i=0;i<50;i++){
        pi = rand()%TAMCROMOSSOMO;
        pj = rand()%TAMCROMOSSOMO;
        aux = capitais[pi];
        capitais[pi] = capitais[pj];
        capitais[pj] = aux;
    }
}
void iniciaPopulacao(struct cidade populacao[TAMPOPULACAO][TAMCROMOSSOMO],struct cidade *capitais){
    for(int i=0;i<TAMPOPULACAO;i++){
        embaralhaCromossomo(capitais);
        copiaCromossomo(populacao[i],capitais);
    }

}
void imprimeCromo(struct cidade *cromo){
    printf("\n");
    for(int i=0;i<TAMCROMOSSOMO;i++)
        printf(" (%d - %s) ",cromo[i].numero,cromo[i].nome);
}
void imprimeCromoPorCodigo(struct cidade *cromo){
    printf("\n");
    for(int i=0;i<TAMCROMOSSOMO;i++)
        printf(" %2.1d ",cromo[i].numero);
}
void imprimePopulacao(struct cidade populacao[TAMPOPULACAO][TAMCROMOSSOMO]){
    for(int i=0;i<TAMPOPULACAO;i++)
        imprimeCromo(populacao[i]);
}
void imprimeCodPopulacao(struct cidade populacao[TAMPOPULACAO][TAMCROMOSSOMO]){
    for(int i=0;i<TAMPOPULACAO;i++)
        imprimeCromoPorCodigo(populacao[i]);
}
float avaliaUmCromossomo(struct cidade *cromo){
    float soma = 0;
    int i;
    for(i=0;i<TAMCROMOSSOMO-1;i++)
        soma += distancias[cromo[i].numero][cromo[i+1].numero];
    soma += distancias[cromo[i].numero][cromo[0].numero];
    return(soma);

}
void fazAvaliacoes(struct cidade populacao[TAMPOPULACAO][TAMCROMOSSOMO],float *avaliacoes){
    for(int i=0;i<TAMPOPULACAO;i++)
        avaliacoes[i] = avaliaUmCromossomo(populacao[i]);
}
void imprimeAvaliacoes(float *avaliacoes){
    printf("\n");
    for(int i=0;i<TAMPOPULACAO;i++)
        printf(" %.2f ",avaliacoes[i]);
}
int torneio(float *avaliacoes,int n){
    int p;
    int m = rand()%TAMPOPULACAO;
//	printf("\n\n%f ",avaliacoes[m]);
    for(int i=1;i<n;i++){
        p = rand()%TAMPOPULACAO;
    //	printf("\n%f",avaliacoes[p]);
        if(avaliacoes[p]<avaliacoes[m])
            m = p;
    }
//	printf("\n O melhor %f",avaliacoes[m]);
    return(m);
}

int achaMelhor(float *avaliacoes){
    int m = 0;
    for(int i=1;i<TAMPOPULACAO;i++){
            if(avaliacoes[i]<avaliacoes[m])
            m = i;
    }
    return(m);
}

int pertence(int j,int pc1,int pc2,struct cidade *pai,struct cidade *filho){
    for(int i=pc1;i<pc2;i++){

        if(pai[j].numero == filho[i].numero)
            return(i);
    }
    return(-1);
}
struct cidade coloca(int i,int pc1,int pc2,struct cidade *pai,struct cidade *filho){

    int r = pertence(i,pc1,pc2,pai,filho);
    if(r == -1)
        return(pai[i]);
    else{
        return(coloca(r,pc1,pc2,pai,filho));
    }
}


void cruzamento(struct cidade *pai1,struct cidade *pai2,struct cidade *filho1
,struct cidade *filho2){
    int aux,pc1,pc2,i;
    do{
        pc1 = rand()%(TAMCROMOSSOMO-1) +1;
        pc2 = rand()%(TAMCROMOSSOMO-1) +1;
    }while(pc1 == pc2);
    if(pc2 < pc1){
        aux = pc1;
        pc1 = pc2;
        pc2 = aux;
    }
//	printf("\nPonto de corte de %d a %d \n",pc1,pc2);
    for(i=pc1;i<pc2;i++){
        filho2[i]=pai1[i];
        filho1[i]=pai2[i];
    }
    for(i=0;i<pc1;i++){
        filho1[i] = coloca(i,pc1,pc2,pai1,filho1);
        filho2[i] = coloca(i,pc1,pc2,pai2,filho2);
    }
    for(i=pc2;i<TAMCROMOSSOMO;i++){
        filho1[i] = coloca(i,pc1,pc2,pai1,filho1);
        filho2[i] = coloca(i,pc1,pc2,pai2,filho2);
    }
}

void mutacao(struct cidade*pai,struct cidade *filho){
    int p1,p2;
    struct cidade aux;
    copiaCromossomo(filho,pai);
    int qm = rand()%TAMCROMOSSOMO+1;
    for(int i=0;i<qm;i++){
        p1 = rand()%TAMCROMOSSOMO;
        p2 = rand()%TAMCROMOSSOMO;
        aux = filho[p1];
        filho[p1] = filho[p2];
        filho[p2] = aux;
    }
}
void copiaPopulacao(struct cidade populacao[TAMPOPULACAO][TAMCROMOSSOMO]
    ,struct cidade populacaoFilhos[TAMPOPULACAO][TAMCROMOSSOMO]){
    for(int i=0;i<TAMPOPULACAO;i++)
        copiaCromossomo(populacao[i],populacaoFilhos[i]);
}

float mediaDasAvaliacoes(float *avaliacoes){
    float resposta = avaliacoes[0];
    for(int i=1;i<TAMPOPULACAO;i++){
        resposta = resposta + avaliacoes[i];
    }
    resposta = resposta/TAMPOPULACAO;
    return(resposta);
}

#endif // AG_H
