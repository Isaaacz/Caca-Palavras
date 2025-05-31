
#ifndef TMATRIZ_H
#define TMATRIZ_H

typedef struct {
    int linhas;
    int colunas;
    char **conteudo;
}TMatriz;

TMatriz* criarMatriz(int linhas, int colunas);

void imprimirMatriz(TMatriz* matriz);

int matrizPreencher(TMatriz* matriz);

#endif //TMATRIZ_H
