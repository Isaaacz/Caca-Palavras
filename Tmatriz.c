#include <stdio.h>
#include <stdlib.h>
#include "Tmatriz.h"

// Função para criar e alocar dinamicamente a matriz do jogo
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
        printf("Erro\n");
        free(matriz);
        return NULL;
    }

    // Aloca memória para as colunas de cada linha
    for (int i = 0; i < linhas; i++) {
        matriz->conteudo[i] = (char*) malloc(colunas * sizeof(char));
        if (matriz->conteudo[i] == NULL) {
            printf("Erro\n");
            free(matriz->conteudo);
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

// Função para imprimir o conteúdo da matriz na tela
void imprimirMatriz(TMatriz* matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("%c ", matriz->conteudo[i][j]);
        }
        printf("\n");
    }
}

// Função para preencher a matriz com caracteres individuais
int matrizPreencher(TMatriz* matriz) {

    // Variavel temporaria para ler cada linha
    char linha[matriz->colunas + 1];

    for (int i = 0; i < matriz->linhas; i++) {
        scanf("%s", linha); // Lê a string de caracteres para a linha atual.
        // Copia os caracteres da variavel para a matriz
        for (int j = 0; j < matriz->colunas; j++) {
            matriz->conteudo[i][j] = linha[j];
        }
    }
    return 1;
}

// Função para desalocar toda a memória dinâmica utilizada pela matriz.
void liberarMatriz(TMatriz* matriz) {
    if (matriz == NULL) {
        return;
    }
    if (matriz->conteudo != NULL) { // Verifica se o conteúdo da matriz foi alocado.

        for (int i = 0; i < matriz->linhas; i++) {
            free(matriz->conteudo[i]);
        }
        free(matriz->conteudo);
    }
    free(matriz);
}