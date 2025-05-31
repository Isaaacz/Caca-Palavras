#ifndef TCOORDENADA_H
#define TCOORDENADA_H

typedef struct {
    int linha;
    int coluna;
} TCoordenada;



TCoordenada criarCoordenada(int i, int j);

int validarCoordenada(TCoordenada c, int maxLinhas, int maxColunas);



#endif
