#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAM 2
#define TAMPOPULACAO 5 //50
struct particula{
	float posicao[TAM];
	float velocidade[TAM];
	float custo;
	float melhorPosicao[TAM];
	float melhorCusto;
};
//Representação do melhor indivíduo
struct melhor{
	float posicao[TAM];
	float custo;
};
float funcaoParabola3D(float *posicao){
	return(posicao[0]*posicao[0]+posicao[1]*posicao[1]);
}
void iniciaPopulacao(struct particula *vetPopulacao){
	int i,j;
	for(i=0;i<TAMPOPULACAO;i++){
		//Foi gerado os valores iniciais da posicao e velocidade
		for(j=0;j<TAM;j++){
			vetPopulacao[i].posicao[j]=rand() %1001 / 1000.00 *8.0 -4.0;
			vetPopulacao[i].velocidade[j] = 0.0;
			vetPopulacao[i].melhorPosicao[j] = vetPopulacao[i].posicao[j];
		}
		//foi calculado o custo
		vetPopulacao[i].custo = 
		       funcaoParabola3D(vetPopulacao[i].posicao);
		vetPopulacao[i].melhorCusto = vetPopulacao[i].custo;
	}
	
}
void imprimeParticula(struct particula p){
	int i;
	printf("\nPosicao: (%.3f,%.3f)",p.posicao[0],p.posicao[1]);
	printf("\nVelocidade: (%.3f,%.3f)",p.velocidade[0]
	,p.velocidade[1]);
	printf("\nCusto: %.3f",p.custo);
	printf("\nMelhor Posicao desta particula: (%.3f,%.3f)"
	   ,p.melhorPosicao[0],p.melhorPosicao[1]);
	printf("\nMelhor Custo desta particual : %.3f\n",p.custo);
}
void imprimePopulacao(struct particula *vetPopulacao){
	for(int i=0;i<TAMPOPULACAO;i++)
		imprimeParticula(vetPopulacao[i]);
}
struct melhor castMelhorParticula(struct particula p){
	struct melhor resposta;
	int i = 0;
	for(i=0;i<TAM;i++)
		resposta.posicao[i] = p.posicao[i];
	resposta.custo = p.custo;
	return resposta;
}


struct melhor calculaMelhorParticula
                   (struct particula * vetPopulacao){
    struct melhor resposta;
	resposta = castMelhorParticula(vetPopulacao[0]);
	for(int i=1;i<TAMPOPULACAO;i++){
		if(vetPopulacao[i].custo < resposta.custo){
			resposta = castMelhorParticula(vetPopulacao[i]);
		}
	}
	return(resposta);
	
}

void imprimeMelhorParticula(struct melhor melhorParticula){
	printf("\n(%.3f,%.3f) Custo-->%.3f",melhorParticula.posicao[0],
	melhorParticula.posicao[1],melhorParticula.custo);
}

void atualizaVelocidadeDaPopulacao(struct particula *vetPopulacao,
 struct melhor melhorParticula, float *w){
 	int i,j;
 	for(j=0;j<TAMPOPULACAO;j++){
 		for(i=0;i<TAM;i++){
	 		vetPopulacao[j].velocidade[i] = (*w)*vetPopulacao[j].velocidade[i] +
	 		rand() %1001 / 1000.00 *  2 * 
	 		(vetPopulacao[j].melhorPosicao[i] - vetPopulacao[j].posicao[i])+
	 		rand() %1001 / 1000.00 *  2 * 
			(melhorParticula.posicao[i] - vetPopulacao[j].posicao[i]);
	 }
	 }
 (*w)=(*w)*0.99;
}

void atualizaPosicao(struct particula *vetPopulacao){
	int i,j;
 	for(j=0;j<TAMPOPULACAO;j++){
 		for(i=0;i<TAM;i++){
 			vetPopulacao[j].posicao[i] += vetPopulacao[j].velocidade[i];
	}
}
}



int main(){
	struct particula vetPopulacao[TAMPOPULACAO];
	struct melhor melhorParticula;
	//Coeficiente de inércia
	float w = 1.0;
	iniciaPopulacao(vetPopulacao);
	melhorParticula = calculaMelhorParticula(vetPopulacao);
	//imprimePopulacao(vetPopulacao);
	//imprimeMelhorParticula(melhorParticula);
	atualizaVelocidadeDaPopulacao(vetPopulacao,melhorParticula,&w);
	atualizaPosicao(vetPopulacao);
	melhorParticula = calculaMelhorParticula(vetPopulacao);
	//Falta verificar se precisa de atualizar o mehor 
	// local que esta particula ja teve
	//imprimePopulacao(vetPopulacao);
	

	

	
	
	
}

