#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define TAM 7
#define FORMIGAS 5

using namespace std;

void imprimirMatriz(float mat[TAM][TAM]){
	for(int i=0;i<TAM;i++){
		printf("\n");
		for(int j=0;j<TAM;j++)
			printf(" %.2f",mat[i][j]);
}}

void geraMatrizN(float caminhos[TAM][TAM],float n[TAM][TAM]){
	int i,j;
	for(i=0;i<7;i++)
		for(j=0;j<7;j++){
			if(caminhos[i][j] < 0.0)
				n[i][j]=-1;	
			else
				n[i][j]=1/caminhos[i][j];	
		}
}

void geraMatrizFeromonio(float feromonio[TAM][TAM]){
	int i,j;
	for(i=0;i<7;i++)
		for(j=0;j<7;j++)
			feromonio[i][j]=0.1;
}

void geraMatrizP(float caminhos[TAM][TAM],float feromonio[TAM][TAM],
	float n[TAM][TAM],float p[TAM][TAM]){
	int i,j;
	float somatorio;
	for(i=0;i<7;i++){
		somatorio = 0.0;
		for(j=0;j<7;j++){
			if(caminhos[i][j]<0)
				p[i][j]=0;
			else{
				p[i][j]= feromonio[i][j]*n[i][j];
				somatorio += p[i][j];
			
			}
		}
		for(j=0;j<7;j++)
			if(caminhos[i][j]>=0){
				p[i][j]=p[i][j]/somatorio;
			}
			
	}
}

int sorteio(float *ps){
	float s = (rand()%100)/100.0;
	int i=0;
	float soma = 0.0;
	do{
		soma += ps[i];
		i++;
	}while(soma<s);
	i--;
	return(i);
}


int main(){
	int i,j,w;
	float somatorio;
	float n[TAM][TAM];
	float p[TAM][TAM];
	float feromonio[TAM][TAM];
	srand(time(NULL));
	vector <int> S;
	float caminhos[TAM][TAM]={
		{-1,5.0,3.1,-1,-1,5.2,-1},
		{5.0,-1,4.9,-1,-1,-1,5.2},
		{3.1,4.9,-1,-1,6,3.2,3},
		{-1,-1,-1,-1,5.5,-1,4.8},
		{-1,-1,6,5.5,-1,4.7,-1},
		{5.2,-1,3.2,-1,4.7,-1,-1},
		{-1,5.2,3,4.8,-1,-1,-1}};
	

	
	geraMatrizFeromonio(feromonio);
    geraMatrizN(caminhos,n);
    geraMatrizP(caminhos,feromonio,n,p);
    int r ;
    S.push_back(0);
    do{
	    r = sorteio(p[S.back()]);
	    S.push_back(r);
	}while(r !=3);
  
    for(i=0;i<S.size();i++)
    	printf(" %d ",S.at(i));
    
    Não deixar repetir
    
    printf("\nO cidade escolhida e %d",r);
    

	imprimirMatriz(p);	
	}



		
			


