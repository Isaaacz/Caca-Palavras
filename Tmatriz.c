#include <stdio.h>
#include <stdlib.h>
#include "Tmatriz.h"

TMatriz* criarMatriz(int linhas, int colunas) {
    TMatriz* matriz = malloc(sizeof(TMatriz));
    if (matriz == NULL) {
        printf("Erro\n");
        return NULL;
    }

    matriz->linhas = linhas;
    matriz->colunas = colunas;

    matriz->conteudo = (char**) malloc(linhas * sizeof(char*));
    if (matriz->conteudo == NULL) {
        printf("Erro: não foi possível alocar memória para as linhas.\n");
        free(matriz);
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        matriz->conteudo[i] = (char*) malloc(colunas * sizeof(char));
        if (matriz->conteudo[i] == NULL) {
            printf("Erro\n");
            for (int j = 0; j < i; j++) {
                free(matriz->conteudo[j]);
            }
            free(matriz->conteudo);
            free(matriz);
            return NULL;
        }
    }

    return matriz;
}

void imprimirMatriz(TMatriz* matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("%c ", matriz->conteudo[i][j]);
        }
        printf("\n");
    }
}

int matrizPreencher(TMatriz* matriz) {
    char linha[matriz->colunas + 1];

    for (int i = 0; i < matriz->linhas; i++) {
        scanf("%s", linha);

         for (int j = 0; j < matriz->colunas; j++) {
            matriz->conteudo[i][j] = linha[j];
        }
    }
    return 1;
}

void liberarMatriz(TMatriz* matriz) {
    if (matriz == NULL) {
        return;
    }
    if (matriz->conteudo != NULL) {
        for (int i = 0; i < matriz->linhas; i++) {
            free(matriz->conteudo[i]);
        }
        free(matriz->conteudo);
    }
    free(matriz);
}
