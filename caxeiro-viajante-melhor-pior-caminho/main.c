#include <stdio.h>				// Biblioteca entrada e saida de dados
#include <locale.h>				// Biblioteca que permite o uso de acentos e caracteres especiais
#include "matriz.c"				// Importa��o do arquivo externo com a fun��o da matriz
#include "cvmelhorcaminho.c"	// Importa��o do arquivo externo que cont�m a fun��o do melhor caminho do Caxeiro Viajante
#include "cvpiorcaminho.c"		// Importa��o do arquivo externo que cont�m a fun��o do pior caminho do Caxeiro Viajante

// C�digo principal (primeiro a ser executado no programa)
int main() {
  	
  	//system("mode 150");		// Para windows: Maximiza o tamanho da tela no tamanho de 150 (usado para poder aparecer todo o conteudo do programa)
  	//system("color A");		// Para windows: Muda cor da fonte do console para verde
  	
	setlocale(LC_ALL, "Portuguese");	// Fun��o que transforma a sa�da dos dados para o padr�o Portugu�s
	imprimeMatriz();		// Chamando a fun��o que imprime a matriz				
	
	printf("\n\n");
	caxeiroViajanteMelhorRota(0);		// Chama a fun��o que mostra o melhor caminho
	printf("\nMELHOR CAMINHO: %d", melhorRota); 	// Mostra a dist�ncia da melhor rota
	
	printf("\n\n");
	caxeiroViajantePiorRota(0);		// Chama a fun��o que mostra o pior caminho
	printf("\nPIOR CAMINHO: %d", piorRota);		// Mostra a dist�ncia da pior rota
	
	printf("\n\n");
	// system("pause");	// Para windows: Da uma pausa no programa antes de ser encerrado
	return 0;
};
