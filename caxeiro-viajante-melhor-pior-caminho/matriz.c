#include <stdio.h>		// Biblioteca entrada e saida de dados
#define MAX 9			// Definindo constante com tamanho da matriz (nesse caso com 9 posições)

// Definindo a matriz com os dados de cada índice
int matriz[MAX][MAX] = {
	{ 0, 18, 35,  1, 20, 25, 29,  9, 13},
	{15,  0, 46, 32, 28, 12, 42, 46, 43},
	{28, 37,  0,  5,  3,  4, 43, 33, 22},
	{17, 19, 46,  0, 27, 22, 39, 20, 13},
	{18, 50, 36, 45,  0, 12, 23, 34, 24},
	{15, 42, 12,  4, 19,  0, 45, 13,  8},
	{38, 10, 24, 42, 30, 29,  0, 36, 41},
	{43, 39,  7, 41, 43, 15, 49,  0,  6},
	{41, 30, 21,  1,  7,  2, 44, 49,  0},

};

// Função que impreme a matriz
void imprimeMatriz() {
	int i,j;
	printf("             ----------------------------------------------------------------------------------------------------------------------\n");
	printf("             |  CHAPADA   |  COROADO   |   CENTRO   | PETROPÓLIS |   ALEIXO   |   JAPIIM   |  ALVORADA  |  COMPENSA  |  DOM PEDRO |\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
	// Bloco que imprime as linhas da matriz (e forma as colunas/matriz)
	for(i = 0; i < MAX; i++){
		printf("|%s", 
			(i == 0) ? "    CHAPADA |":
			(i == 1) ? "    COROADO |":
			(i == 2) ? "     CENTRO |":
			(i == 3) ? " PETROPÓLIS |":
			(i == 4) ? "     ALEIXO |":
			(i == 5) ? "     JAPIIM |":
			(i == 6) ? "   ALVORADA |":
			(i == 7) ? "   COMPENSA |":
					   "  DOM PEDRO |"
		);		
		for(j = 0; j < MAX; j++){
			printf("     %2d     |", matriz[i][j]);
		};
		printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
	};	
};
