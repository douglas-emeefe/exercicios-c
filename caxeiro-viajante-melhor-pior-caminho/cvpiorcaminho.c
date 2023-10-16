#include <stdio.h>

int piorRota = 0, bairroVisitadosPior[MAX];

/* 
 * A função começa iterando sobre todas as cidades não visitadas. 
 * Para cada cidade, a função verifica se a distância entre a cidade atual e a cidade 
 * não visitada é menor que a distância mínima atual. Se for, a função atualiza 
 * a distância mínima e a próxima cidade.
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
 * A função começa imprimindo o nome da cidade atual. 
 * A função então chama a função custoMinimo() para encontrar a próxima cidade. 
 * A função então chama a si mesma novamente, passando a próxima cidade como entrada. 
 * O processo continua até que todas as cidades tenham sido visitadas
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
			printf("PETROPÓLIS -> ");
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
