#include <stdio.h>
#include <stdlib.h>
#include "TListaPalavras.h"
#include "TPalavra.h"

// Função para criar e alocar dinamicamente uma nova lista de palavras
TListaPalavras* criarListaPalavras(int quantidade) {
    TListaPalavras* lista = malloc(sizeof(TListaPalavras));
    if (lista == NULL) {
        return NULL;
    }

    // Recebe a quantidade de palavras que a lista vai armazenar
    lista->quantidade = quantidade;
    // Aloca um vetor de estruturas da TPalavra para armazenar as palavras
    lista->palavras = malloc(quantidade * sizeof(TPalavra));

    if (lista->palavras == NULL) {
        free(lista);
        return NULL;
    }

    return lista;
}

// Função para preencher a lista de palavras com os dados lidos da entrada
void preencherListaPalavras(TListaPalavras* lista) {

    // Variavel temporaria para ler cada nova palavra da entrada
    char novaPalavra[100];

    for (int i = 0; i < lista->quantidade; i++) {
        scanf("%s", novaPalavra);
        // Cria uma TPalavra a partir do texto lido e a armazena na posição atual do vetor
        lista->palavras[i] = criarPalavra(novaPalavra);
    }
}

// Função para desalocar toda a memória utilizada pela lista de palavras.

void liberarListaPalavras(TListaPalavras* lista) {
    free(lista->palavras);
    free(lista);
}

// Função para imprimir os resultados da busca de cada palavra
void imprimirResultadosListaPalavras(TListaPalavras* lista) {
    for (int i = 0; i < lista->quantidade; i++) {

        TPalavra p = lista->palavras[i];

        if (p.encontrada) {
            // Imprime a palavra e suas coordenadas de início e fim se for encontrada
            printf("%s: (%d,%d) -> (%d,%d)\n", p.palavra, p.inicio.linha, p.inicio.coluna, p.fim.linha, p.fim.coluna);
        } else {
            // Imprime (0,0) se não for encontrada
            printf("%s: (0,0)\n", p.palavra);
        }
    }
}