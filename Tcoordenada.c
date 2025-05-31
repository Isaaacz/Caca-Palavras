#include "Tcoordenada.h"

TCoordenada criarCoordenada(int i, int j) {
    TCoordenada c;
    c.linha = i;
    c.coluna = j;
    return c;
}

int validarCoordenada(TCoordenada c, int maxLinhas, int maxColunas) {
    return c.linha >= 0 && c.linha < maxLinhas &&
           c.coluna >= 0 && c.coluna < maxColunas;
}


