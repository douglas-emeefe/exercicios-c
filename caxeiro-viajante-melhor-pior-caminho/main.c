#include <stdio.h>			 // Biblioteca entrada e saida de dados
#include <locale.h>			 // Biblioteca que permite o uso de acentos e caracteres especiais
#include "matriz.c"			 // Importação do arquivo externo com a função da matriz
#include "cvmelhorcaminho.c" // Importação do arquivo externo que contém a função do melhor caminho do Caxeiro Viajante
#include "cvpiorcaminho.c"	 // Importação do arquivo externo que contém a função do pior caminho do Caxeiro Viajante

// Código principal (primeiro a ser executado no programa)
int main()
{

	// system("mode 150");		// Para windows: Maximiza o tamanho da tela no tamanho de 150 (usado para poder aparecer todo o conteudo do programa)
	// system("color A");		// Para windows: Muda cor da fonte do console para verde

	setlocale(LC_ALL, "Portuguese"); // Função que transforma a saída dos dados para o padrão Português
	imprimeMatriz();				 // Chamando a função que imprime a matriz

	printf("\n\n");
	caxeiroViajanteMelhorRota(0);				// Chama a função que mostra o melhor caminho
	printf("\nMELHOR CAMINHO: %d", melhorRota); // Mostra a distância da melhor rota

	printf("\n\n");
	caxeiroViajantePiorRota(0);				// Chama a função que mostra o pior caminho
	printf("\nPIOR CAMINHO: %d", piorRota); // Mostra a distância da pior rota

	printf("\n\n");
	// system("pause");	// Para windows: Da uma pausa no programa antes de ser encerrado
	return 0;
};
