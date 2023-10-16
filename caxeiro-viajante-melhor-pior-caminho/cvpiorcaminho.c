#include <stdio.h>

int piorRota = 0, bairroVisitadosPior[MAX];

/* 
 * A fun��o come�a iterando sobre todas as cidades n�o visitadas. 
 * Para cada cidade, a fun��o verifica se a dist�ncia entre a cidade atual e a cidade 
 * n�o visitada � menor que a dist�ncia m�nima atual. Se for, a fun��o atualiza 
 * a dist�ncia m�nima e a pr�xima cidade.
 */
int custoMaximo(int bairroAtual){
    int maximo = 0, proximoBairro = -1, i;
    for(i = 0; i < MAX; i++){
        if(matriz[bairroAtual][i] != 0 && bairroVisitadosPior[i] == 0){
            if(matriz[bairroAtual][i] > maximo){
                maximo = matriz[bairroAtual][i];
                proximoBairro = i;
            };
        };
    };
    if(maximo != 0){
        piorRota = piorRota + maximo;
    };
    return proximoBairro;
};
/*
 * A fun��o come�a imprimindo o nome da cidade atual. 
 * A fun��o ent�o chama a fun��o custoMinimo() para encontrar a pr�xima cidade. 
 * A fun��o ent�o chama a si mesma novamente, passando a pr�xima cidade como entrada. 
 * O processo continua at� que todas as cidades tenham sido visitadas
 */
void caxeiroViajantePiorRota(int bairroAtual){
    int proximoBairro = 0;
    bairroVisitadosPior[bairroAtual] = 1;
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
    proximoBairro = custoMaximo(bairroAtual);
    if(proximoBairro == -1){
        proximoBairro = 0;
        printf("CHAPADA");
        piorRota = piorRota + matriz[bairroAtual][proximoBairro];
        return;
    };
    caxeiroViajantePiorRota(proximoBairro);
};
