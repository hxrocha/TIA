#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <vector>
#define TAM 7
#define FORMIGAS 5

using namespace std;

void imprimirMatriz(float mat[TAM][TAM]){
	for(int i=0;i<TAM;i++){
		printf("\n");
		for(int j=0;j<TAM;j++)
			printf(" %.4f",mat[i][j]);
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

int eInedita(int r,vector<int>S){
	int resposta = 1;	
	for(int i=0;i<S.size();i++)
		if(r == S.at(i)){
			resposta = 0;
			break;
		}
	return resposta;
}

float calculaDistancia(vector<int>S,float matrizCaminho[TAM][TAM]){
	float resposta = 0.0;
	for(int i=0;i<S.size()-1;i++)
		resposta += matrizCaminho[S.at(i)][S.at(i+1)];
	return(resposta);
}





int main(){
	int i,j,w;
	float somatorio;
	float n[TAM][TAM];
	float p[TAM][TAM];
	float feromonio[TAM][TAM];
	srand(time(NULL));
	vector <int> Sk,S;
	float L = FLT_MAX;
	int K = 5;
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
	

	
	geraMatrizFeromonio(feromonio);
    geraMatrizN(caminhos,n);
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
	
	float matVarFeromonio[TAM][TAM];
	for(i=0;i<TAM;i++){
		for(j=0;j<TAM;j++)
			matVarFeromonio[i][j]=0;
	}
	for(int i=0;i<K;i++){
		for(j=0;j<vetCaminhos[i].size()-1;j++)
    		matVarFeromonio[vetCaminhos[i].at(j)][vetCaminhos[i].at(j+1)] 
			  +=1/vetDistancias[i];
	}
		
	
	
	
	
	
	for(int i=0;i<K;i++){
		printf("\n");
		for(j=0;j<vetCaminhos[i].size();j++)
    		printf(" %d ",vetCaminhos[i].at(j));
    	printf(" - %.2f",vetDistancias[i]);
	}
	
	
	
	
	 printf("\n");
    for(i=0;i<S.size();i++)
    	printf(" %d ",S.at(i));	
    printf("\nA melhor distancia e %.2f",L);
    	
   
   
   
   
   
   
   
    	
    	
   
	
   
	  
  
  
  
  
  
    
    //Não deixar repetir
    
    printf("\nO cidade escolhida e %d\n",r);
    

	imprimirMatriz(matVarFeromonio);	
	}



		
			


