#include <stdio.h>  //Biblioteca de entrada e saída de dados
#include <stdlib.h> //Biblioteca que contém as funções de alocação de memória

// Denifinição da estrutura da lista
struct Lista
{
    int dados;              // Variável para armazenar valor inteiro
    struct Lista *proximo;  // Ponteiro que aponta para o próximo nó
    struct Lista *anterior; // Ponteiro que aponta para o nó anterior
    // A declaração desses dois ponteiros permite a navegação bidirecional na lista
};

typedef struct Lista Lista; // Cria um tipo personalizado chamado Lista para simplificar a declaração de variáveis do tipo struct Lista

// Função que cria e insere um novo nó na lista
void criarLista(Lista **noInicial, int dados)
{
    Lista *novoNo = (Lista *)malloc(sizeof(Lista)); // Aloca memória para um novo nó, e um ponteiro novoNo é usado para acesar-lo.
    // Preenchedo os dados da estrutura
    novoNo->dados = dados;
    novoNo->proximo = NULL;  // Atribuido valor nulo a ponteiro
    novoNo->anterior = NULL; // Atribuido valor nulo a ponteiro

    // Verifica se a lista está vazia, o novo nó se torna o primeiro nó da lista.
    if (*noInicial == NULL)
    {
        *noInicial = novoNo;
    }
    // Caso não seja vazio, novo nó é adicionado ao final da lista, mantendo a ordem e os ponteiros proximo e anterior atualizados.
    else
    {
        Lista *noAtual = *noInicial;
        while (noAtual->proximo != NULL)
        {
            noAtual = noAtual->proximo;
        }
        noAtual->proximo = novoNo;
        novoNo->anterior = noAtual;
    }
}

/* Função que divide a lista em 2(duas), uma anterior ao pivô (chamado de chave) e outro depois do pivõ
 * A função recebe quatro argumentos:
 *  - Um ponteiro duplo noInicial, que aponta para o início da lista original
 *  - Dois ponteiros duplos anteriorChave e depoisChave para armazenar as partes da lista antes e depois da chave
 *  - Um valor inteiro chave que determina o ponto de divisão
 */
void dividirLista(Lista **noInicial, Lista **anteriorChave, Lista **depoisChave, int chave)
{
    Lista *noAtual = *noInicial; // Cria um ponteiro que é inicializado com inicio da lista original

    // Esse loop percorre a lista original até que noAtual seja nulo ou até que o valor dados do nó atual seja igual à chave.
    while (noAtual != NULL && noAtual->dados != chave)
    {
        criarLista(anteriorChave, noAtual->dados); // Essa parte do código faz uma cópia dos nós antes da chave para a lista anteriorChave
        noAtual = noAtual->proximo;
    }

    // Verifica se no atual é nulo, se for é porque a chave não foi encontrada na lista original e a função retorna
    if (noAtual == NULL)
    {
        return;
    }

    // Se a chave for encontrada na lista original, o ponteiro noAtual é movido para o próximo nó, para que possamos começar a copiar os nós após a chave
    noAtual = noAtual->proximo;

    // Esse loop percorre a lista original enquanto noAtual for diferente de nulo
    while (noAtual != NULL)
    {
        criarLista(depoisChave, noAtual->dados); // Faz a cópia dos nós da lista original para a lista depoisChave
        noAtual = noAtual->proximo;
    }
}

// Função que imprime a lista
void imprimirLista(Lista *noInicial)
{
    Lista *noAtual = noInicial;
    while (noAtual != NULL)
    {
        printf("%d <-> ", noAtual->dados);
        noAtual = noAtual->proximo;
    }
    printf("NULL\n\n");
}

int main()
{
    int chave = 0; // Variavel chave iniciada com valor 0 (zero), usada para armazenar o valor da chave fornecida pelo usuário
    Lista *listaPrincipal = NULL;

    // Inserindo dados da lista
    criarLista(&listaPrincipal, 1);
    criarLista(&listaPrincipal, 2);
    criarLista(&listaPrincipal, 3);
    criarLista(&listaPrincipal, 4);
    criarLista(&listaPrincipal, 5);
    criarLista(&listaPrincipal, 6);
    criarLista(&listaPrincipal, 7);
    criarLista(&listaPrincipal, 8);
    criarLista(&listaPrincipal, 9);
    criarLista(&listaPrincipal, 10);

    printf("Lista original:\n");
    imprimirLista(listaPrincipal); // Imprime lista Original

    printf("Digite onde quer dividir a lista: ");
    scanf("%d", &chave); // Faz a leitura do valor da chave

    printf("\n");

    // Declarando dois ponteiros com valores nulos, que irão receber a lista antes da chave e depois da chave
    Lista *anteriorChaveList = NULL;
    Lista *depoisChaveList = NULL;

    // Chamando a função que dividi a lista
    dividirLista(&listaPrincipal, &anteriorChaveList, &depoisChaveList, chave);

    printf("Lista antes da chave %d:\n", chave);
    imprimirLista(anteriorChaveList); // Imprimindo a lista anterior da chave

    printf("Lista após a chave %d:\n", chave);
    imprimirLista(depoisChaveList); // Imprimindo a lista depois da chave

    return 0;
}