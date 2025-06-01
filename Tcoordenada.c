#include "Tcoordenada.h"

// Função para criar e inicializar uma nova coordenada.
TCoordenada criarCoordenada(int i, int j) {
    TCoordenada c;
    c.linha = i;
    c.coluna = j;
    return c;
}

// Função para validar se uma coordenada está dentro dos limites de uma matriz.
int validarCoordenada(TCoordenada c, int maxLinhas, int maxColunas) {
    return c.linha >= 0 && c.linha < maxLinhas &&
           c.coluna >= 0 && c.coluna < maxColunas;
}