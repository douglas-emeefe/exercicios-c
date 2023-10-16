#include <stdio.h>		// Biblioteca entrada e saida de dados

int melhorRota = 0, bairroVisitadosMelhor[MAX];		// Declara��o de vari�veis

/* 
 * A fun��o come�a iterando sobre todas as cidades n�o visitadas. 
 * Para cada cidade, a fun��o verifica se a dist�ncia entre a cidade atual e a cidade 
 * n�o visitada � menor que a dist�ncia m�nima atual. Se for, a fun��o atualiza 
 * a dist�ncia m�nima e a pr�xima cidade.
 */
int custoMinimo(int bairroAtual){	
	int minimo = 51, proximoBairro = -1, i;
	for(i = 0; i < MAX; i++){
		if(matriz[bairroAtual][i] != 0 && bairroVisitadosMelhor[i] == 0){
			if(matriz[bairroAtual][i] < minimo){
				minimo = matriz[bairroAtual][i];
				proximoBairro = i;
			};
		};
	};
	if(minimo != 51){
		melhorRota = melhorRota + minimo;
	};
	return proximoBairro;
};
/*
 * A fun��o come�a imprimindo o nome da cidade atual. 
 * A fun��o ent�o chama a fun��o custoMinimo() para encontrar a pr�xima cidade. 
 * A fun��o ent�o chama a si mesma novamente, passando a pr�xima cidade como entrada. 
 * O processo continua at� que todas as cidades tenham sido visitadas
 */
void caxeiroViajanteMelhorRota(int bairroAtual){
	int proximoBairro = 0;
	bairroVisitadosMelhor[bairroAtual] = 1;
	switch (bairroAtual){
		case 0:
			printf("CHAPADA -> ");
			break;
		case 1:
			printf("COROADO -> ");
			break;
		case 2:
			printf("CENTRO -> ");
			break;
		case 3:
			printf("PETROP�LIS -> ");
			break;
		case 4:
			printf("ALEIXO -> ");
			break;
		case 5:
			printf("JAPIIM -> ");
			break;
		case 6:
			printf("ALVORADA -> ");
			break;
		case 7:
			printf("COMPENSA -> ");
			break;
		case 8:
			printf("DOM PEDRO -> ");
			break;
	};

	proximoBairro = custoMinimo(bairroAtual);
	if(proximoBairro == -1){
		proximoBairro = 0;
		printf("CHAPADA");
		melhorRota = melhorRota + matriz[bairroAtual][proximoBairro];
		return;
	};
	caxeiroViajanteMelhorRota(proximoBairro);
};
