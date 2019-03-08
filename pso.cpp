#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMPOPULACAO 50
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
void multiplica(float w,float *vetorDeTrabalho){
	for(int i=0;i<TAMPARTICULA;i++)
		vetorDeTrabalho[i] = w * vetorDeTrabalho[i];
}

void subtracaoVetor(float *vetorResposta,float *vetor1,float *vetor2){
	for(int i = 0;i<TAMPARTICULA;i++)
		vetorResposta[i]=vetor1[i]-vetor2[i];
}

void somar3Vetores(float *vetorAtual,float *vetorA,float *vetorB){
		for(int i = 0;i<TAMPARTICULA;i++)
			vetorAtual[i] += vetorA[i]+vetorB[i];
}

void somarPosicaoVelocidade(float *vetorPosicao,float *vetorVelocidade){
	for(int i = 0;i<TAMPARTICULA;i++)
			vetorPosicao[i] += vetorVelocidade[i];
}

void copiarPosicaoDeParticula(float *posicaoDestino,float *posicaoOrigem){
	for(int i = 0;i<TAMPARTICULA;i++)
		posicaoDestino[i]=posicaoOrigem[i];
}

void iteracao(struct particula *populacaoDeParticulas,
    struct melhor *melhorParticuasDeTodas,
    float *w,float *respostaVetorCognitive,float *respostaVetorSocial	

){
	float r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	
	float coefAmortecimento = 0.99;
	float coefAceleracaoPessoal = 2.0;
	float coefAceleracaoSocial = 2.0;
	
	for(int i =0;i<TAMPOPULACAO;i++){
		populacaoDeParticulas[i];
		multiplica(*w,populacaoDeParticulas[i].velocidade);
		
		subtracaoVetor(respostaVetorCognitive,populacaoDeParticulas[i].melhorPosicao,populacaoDeParticulas[i].posicao);
		multiplica(r1*coefAceleracaoPessoal,respostaVetorCognitive);
		
		subtracaoVetor(respostaVetorSocial,melhorParticuasDeTodas->posicao,	populacaoDeParticulas[i].posicao);
		multiplica(r2*coefAceleracaoSocial,respostaVetorSocial);
		
		somar3Vetores(populacaoDeParticulas[i].velocidade,respostaVetorCognitive,respostaVetorSocial);
		
		somarPosicaoVelocidade(populacaoDeParticulas[i].posicao,populacaoDeParticulas[i].velocidade);
		populacaoDeParticulas[i].custo = calcularCusto(populacaoDeParticulas[i].posicao);
		
		if(populacaoDeParticulas[i].custo < populacaoDeParticulas[i].melhorCusto){
			populacaoDeParticulas[i].melhorCusto = populacaoDeParticulas[i].custo;
			copiarPosicaoDeParticula(populacaoDeParticulas[i].melhorPosicao,
			populacaoDeParticulas[i].posicao);
		}
		
		if(populacaoDeParticulas[i].custo < melhorParticuasDeTodas->custo){
			melhorParticuasDeTodas->custo = populacaoDeParticulas[i].custo;
			for(int j =0;j<TAMPARTICULA;j++)
				melhorParticuasDeTodas->posicao[j] = populacaoDeParticulas[i].posicao[j];
		}
						
	}
	(*w) = (*w)*coefAmortecimento;
	printf("\n o valor de w e %.2f",*w);
	
	
}


int main(){
	struct particula populacaoDeParticulas[TAMPOPULACAO];
	struct melhor melhorParticuasDeTodas;
	inicializaPopulacaoDeParticulas(populacaoDeParticulas);
	srand(time(NULL));
	melhorParticuasDeTodas = retornaMelhorParticula(populacaoDeParticulas);
	float w = 1;
	float respostaVetorCognitive[TAMPARTICULA]= {0.0,0.0,0.0,0.0,0.0};
	float respostaVetorSocial[TAMPARTICULA] = {0.0,0.0,0.0,0.0,0.0};
	for(int it=0;it<100;it++)	
		iteracao(populacaoDeParticulas,&melhorParticuasDeTodas,&w,respostaVetorCognitive,respostaVetorSocial);
	
	melhorParticuasDeTodas = retornaMelhorParticula(populacaoDeParticulas);
	imprimeMelhorParticula(melhorParticuasDeTodas);
//	imprimirPopulacaoDeParticulas(populacaoDeParticulas);

}
