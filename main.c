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

    TMatriz* matriz = criarMatriz(linhas, colunas);

    if (matriz == NULL) {
        printf("Falha ao criar a matriz.\n");
        return 1;
    }

    matrizPreencher(matriz);

    printf("Digite o numero de palavras a serem buscadas: ");
    scanf("%d", &quantidadePalavras);

    TListaPalavras* lista = criarListaPalavras(quantidadePalavras);

    if (lista == NULL) {
        printf("Falha ao criar a lista de palavras.\n");
        return 1;
    }

    preencherListaPalavras(lista);

    buscarTodasPalavras(matriz, lista);

    imprimirResultadosListaPalavras(lista);

    liberarListaPalavras(lista);

    return 0;
}