#include "Tbusca.h"
#include <string.h>

int verificarPalavraDirecao(TMatriz* matriz, TPalavra* palavra, int linha, int coluna, int deltaLinha, int deltaColuna) {

    int tamanho = strlen(palavra->palavra);

    for (int i = 0; i < tamanho; i++) {
        int novaLinha = linha + i * deltaLinha;
        int novaColuna = coluna + i * deltaColuna;

        if (!validarCoordenada(criarCoordenada(novaLinha, novaColuna), matriz->linhas, matriz->colunas)) {
            return 0;
        }
        if (matriz->conteudo[novaLinha][novaColuna] != palavra->palavra[i]) {
            return 0;
        }
    }

    palavra->encontrada = 1;
    palavra->inicio = criarCoordenada(linha, coluna);
    palavra->fim = criarCoordenada(
        linha + (tamanho - 1) * deltaLinha,
        coluna + (tamanho - 1) * deltaColuna
    );
    return 1;
}

int buscarPalavra(TMatriz* matriz, TPalavra* palavra) {
    int direcoes[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            for (int d = 0; d < 8; d++) {
                int dl = direcoes[d][0];
                int dc = direcoes[d][1];

                if (verificarPalavraDirecao(matriz, palavra, i, j, dl, dc)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void buscarTodasPalavras(TMatriz* matriz, TListaPalavras* lista) {
    for (int i = 0; i < lista->quantidade; i++) {
        // Agora, passamos o endereço da TPalavra que já está na lista
        // para buscarPalavra preencher diretamente os campos.
        buscarPalavra(matriz, &(lista->palavras[i])); // Passa o endereço da TPalavra na lista
    }
    // A impressão agora seria feita por uma função em TListaPalavras.c ou no main,
    // após o loop de busca.
}
