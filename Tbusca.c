#include "Tbusca.h"
#include <string.h>

// Função que tenta encontrar uma palavra a partir de uma posição inicial
int verificarPalavraDirecao(TMatriz* matriz, TPalavra* palavra, int linha, int coluna, int dLinha, int dColuna) {

    // Obtém o tamanho da palavra
    int tamanho = strlen(palavra->palavra);

    // Busca por cada caractere da palavra para comparar com a matriz
    for (int i = 0; i < tamanho; i++) {

        // Calcula a próxima coordenada na matriz
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;

        // Verifica se a nova coordenada está dentro dos limites da matriz
        if (!validarCoordenada(criarCoordenada(novaLinha, novaColuna), matriz->linhas, matriz->colunas)) {
            return 0;
        }

        // Compara o caractere da matriz com o caractere especifico da palavra
        if (matriz->conteudo[novaLinha][novaColuna] != palavra->palavra[i]) {
            return 0;
        }
    }

    // Atualiza o status da palavra como encontrada e registra suas coordenadas de início e fim
    palavra->encontrada = 1;
    palavra->inicio = criarCoordenada(linha, coluna);
    palavra->fim = criarCoordenada(
        linha + (tamanho - 1) * dLinha,
        coluna + (tamanho - 1) * dColuna
    );
    return 1;
}

// Função que busca uma única palavra em toda a matriz, em todas as direções.
int buscarPalavra(TMatriz* matriz, TPalavra* palavra) {

    // Matriz que define as direçoes
    int direcoes[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };


    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            for (int d = 0; d < 8; d++) {
                // cria as variações de linha e coluna para a direção atual
                int dl = direcoes[d][0];
                int dc = direcoes[d][1];

                // Chama a função verificarPalavraDirecao para verificar se a palavra existe nesta direção
                if (verificarPalavraDirecao(matriz, palavra, i, j, dl, dc)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Função que controla a busca de todas as palavras contidas na lista.
void buscarTodasPalavras(TMatriz* matriz, TListaPalavras* lista) {
    // Percorre cada palavra na lista fornecida.
    for (int i = 0; i < lista->quantidade; i++) {
        buscarPalavra(matriz, &(lista->palavras[i]));
    }
}