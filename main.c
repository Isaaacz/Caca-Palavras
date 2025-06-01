#include <stdio.h>
#include "Tmatriz.h"
#include "TlistaPalavras.h"
#include "Tbusca.h"

int main() {

    int linhas;
    int colunas;
    int quantidadePalavras;

    printf("Digite o numero de linhas e de colunas: ");
    scanf("%d %d", &linhas, &colunas);

    // Aloca e inicializa a estrutura da matriz na memória
    TMatriz* matriz = criarMatriz(linhas, colunas);

    // Verifica se a alocação da matriz foi feita
    if (matriz == NULL) {
        printf("Falha ao criar a matriz.\n");
        return 1; // Encerra o programa
    }

    // Lê os caracteres da entrada e preenche a matriz
    matrizPreencher(matriz);

    printf("Digite o numero de palavras a serem buscadas: ");
    scanf("%d", &quantidadePalavras);

    // Aloca e inicializa a lista que armazenará as palavras a serem buscadas
    TListaPalavras* lista = criarListaPalavras(quantidadePalavras);

    if (lista == NULL) {
        printf("Falha ao criar a lista de palavras.\n");
        // Libera a memória da matriz
        liberarMatriz(matriz);
        return 1; // Encerra o programa
    }

    // Lê as palavras da entrada e as armazena na lista
    preencherListaPalavras(lista);

    // Inicia o processo de busca
    buscarTodasPalavras(matriz, lista);

    // Exibe os resultados
    imprimirResultadosListaPalavras(lista);

    // Libera a memoria
    liberarListaPalavras(lista);
    liberarMatriz(matriz);

    return 0;
}