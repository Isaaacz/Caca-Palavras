#include <stdio.h>
#include <stdlib.h>
#include "TListaPalavras.h"
#include "TPalavra.h"

TListaPalavras* criarListaPalavras(int quantidade) {
    TListaPalavras* lista = malloc(sizeof(TListaPalavras));
    if (lista == NULL) {
        return NULL;
    }

    lista->quantidade = quantidade;
    lista->palavras = malloc(quantidade * sizeof(TPalavra));

    if (lista->palavras == NULL) {
        free(lista);
        return NULL;
    }

    return lista;
}

void preencherListaPalavras(TListaPalavras* lista) {
    char novaPalavra[100];
    for (int i = 0; i < lista->quantidade; i++) {
        scanf("%s", novaPalavra);
        lista->palavras[i] = criarPalavra(novaPalavra);
    }
}

void liberarListaPalavras(TListaPalavras* lista) {
    free(lista->palavras);
    free(lista);
}

void imprimirResultadosListaPalavras(TListaPalavras* lista) {
    for (int i = 0; i < lista->quantidade; i++) {
        TPalavra p = lista->palavras[i];

        if (p.encontrada) {
            printf("%s: (%d,%d) -> (%d,%d)\n", p.palavra, p.inicio.linha, p.inicio.coluna, p.fim.linha, p.fim.coluna);
        } else {
            printf("%s: (0,0)\n", p.palavra);
        }
    }
}