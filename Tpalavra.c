#include <string.h>
#include "TPalavra.h"
#include "Tcoordenada.h"

TPalavra criarPalavra(char* texto) {
    TPalavra p;
    strcpy(p.palavra, texto);
    p.encontrada = 0;
    p.inicio = criarCoordenada(-1, -1);
    p.fim = criarCoordenada(-1, -1);
    return p;
}

