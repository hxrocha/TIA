#include <stdio.h>
#include <stdlib.h>
#define TAMPOPULACAO 6
#define TAMPARTICULA 5

struct particula{
	float posicao[TAMPARTICULA];
	float velocidade[TAMPARTICULA];
	float custo;
	float melhorPosicao[TAMPARTICULA];
	float melhorCusto;
};
struct melhor{
	float posicao[TAMPARTICULA];
	float custo;
};

//Calcula o custo de uma particula
float calcularCusto(float *posicao){
	float resposta = 0.0;
	for(int j=0;j<TAMPARTICULA;j++)
		resposta = resposta +(posicao[j]*posicao[j]);
	return(resposta);
	
}
//Inicia uma populacao de particulas
inicializaPopulacaoDeParticulas(struct particula *populacaoDeParticulas){
	int i,j;
	for(i=0;i<TAMPOPULACAO;i++){
		for(j=0;j<TAMPARTICULA;j++){
			populacaoDeParticulas[i].posicao[j]=(rand()%2001 - 1000)/100.0;
			populacaoDeParticulas[i].melhorPosicao[j]=populacaoDeParticulas[i].posicao[j];
			populacaoDeParticulas[i].velocidade[j]=0;
		}
		populacaoDeParticulas[i].custo = calcularCusto(populacaoDeParticulas[i].posicao);
		populacaoDeParticulas[i].melhorCusto = populacaoDeParticulas[i].custo;
		}
		}
// Imprime qualquer campo do tipo vetor de uma particula		
void imprime(char *nome,float *vet){
		int j;
		printf("\n %s: [",nome);
		for(j=0;j<TAMPARTICULA;j++){
			if(j == TAMPARTICULA-1)
				printf("%.2f",vet[j]);
			else
				printf("%.2f,",vet[j]);
		}
		printf("]");
}		
//Imprime uma populacao de particulas		
imprimirPopulacaoDeParticulas(struct particula * populacaoDeParticulas){
	int i,j;
	for(i=0;i<TAMPOPULACAO;i++){
		printf("\n Particula: %d",i);
		imprime("Posicao",populacaoDeParticulas[i].posicao);
		imprime("Velocidade",populacaoDeParticulas[i].velocidade);
		printf("\n O custo desta particuala: %.2f",populacaoDeParticulas[i].custo);
		imprime("Melhor posicao desta particula",populacaoDeParticulas[i].melhorPosicao);
		printf("\n O melhor custo desta particuala: %.2f",populacaoDeParticulas[i].melhorCusto);
		printf("\n------------------------------------------------------");
		}
}
// refatora um struct particula para o tipo struct melhor
struct melhor refatoraParticula(struct particula particula){
	struct melhor p;
	int i;
	for(i=0;i<TAMPARTICULA;i++)
		p.posicao[i]=particula.posicao[i];
	p.custo = particula.custo;
	return(p);
}
// refatora um struct particula para o tipo struct melhor
struct melhor refatoraParticula(struct particula *particula){
	struct melhor p;
	int i;
	for(i=0;i<TAMPARTICULA;i++)
		p.posicao[i]=(*particula).posicao[i];
	p.custo = (*particula).custo;
	return(p);
}


struct melhor retornaMelhorParticula(struct particula * populacaoDeParticulas){
	struct melhor melhorParticuasDeTodas = refatoraParticula(populacaoDeParticulas[0]);
	for(int i=0;i<TAMPOPULACAO;i++){
		if(populacaoDeParticulas[i].custo < melhorParticuasDeTodas.custo)
			melhorParticuasDeTodas = refatoraParticula(populacaoDeParticulas[i]);
	}
	return(melhorParticuasDeTodas);
}

void imprimeMelhorParticula(struct melhor melhorParticuasDeTodas){
	printf("\nA melhor particula e : [");
	for(int i=0;i<TAMPARTICULA;i++){
		if(i == (TAMPARTICULA-1))
			printf("%.2f",melhorParticuasDeTodas.posicao[i]);
		else
			printf("%.2f,",melhorParticuasDeTodas.posicao[i]);
	}
	printf("] e o custo e %.2f",melhorParticuasDeTodas.custo);
}
	
int main(){
	struct particula populacaoDeParticulas[TAMPOPULACAO];
	struct melhor melhorParticuasDeTodas;
	inicializaPopulacaoDeParticulas(populacaoDeParticulas);
	melhorParticuasDeTodas = retornaMelhorParticula(populacaoDeParticulas);
	imprimeMelhorParticula(melhorParticuasDeTodas);
	imprimirPopulacaoDeParticulas(populacaoDeParticulas);

}
