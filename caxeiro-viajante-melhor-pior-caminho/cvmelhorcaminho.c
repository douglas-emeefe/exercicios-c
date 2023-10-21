#include <stdio.h> // Biblioteca entrada e saida de dados

int melhorRota = 0, bairroVisitadosMelhor[MAX]; // Declaração de variáveis

/*
 * A função começa iterando sobre todos os bairros não visitadas.
 * Para cada bairro, a função verifica se a distância entre o bairro atual e o bairro
 * não visitada é menor que a distância mínima atual. Se for, a função atualiza
 * a distância mínima e o próximo bairro.
 */
int custoMinimo(int bairroAtual)
{
	int minimo = 51, proximoBairro = -1, i;
	for (i = 0; i < MAX; i++)
	{
		if (matriz[bairroAtual][i] != 0 && bairroVisitadosMelhor[i] == 0)
		{
			if (matriz[bairroAtual][i] < minimo)
			{
				minimo = matriz[bairroAtual][i];
				proximoBairro = i;
			};
		};
	};
	if (minimo != 51)
	{
		melhorRota = melhorRota + minimo;
	};
	return proximoBairro;
};
/*
 * A função começa imprimindo o nome do bairro atual.
 * A função então chama a função custoMinimo() para encontrar o próximo bairro.
 * A função então chama a si mesma novamente, passando o próximo bairro como entrada.
 * O processo continua até que todos os bairros tenham sido visitadas
 */
void caxeiroViajanteMelhorRota(int bairroAtual)
{
	int proximoBairro = 0;
	bairroVisitadosMelhor[bairroAtual] = 1;
	switch (bairroAtual)
	{
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

	proximoBairro = custoMinimo(bairroAtual);
	if (proximoBairro == -1)
	{
		proximoBairro = 0;
		printf("CHAPADA");
		melhorRota = melhorRota + matriz[bairroAtual][proximoBairro];
		return;
	};
	caxeiroViajanteMelhorRota(proximoBairro);
};
