#ifndef TPALAVRA_H
#define TPALAVRA_H

#include "Tcoordenada.h"

typedef struct {
    char palavra[100];
    int encontrada;
    TCoordenada inicio;
    TCoordenada fim;
} TPalavra;

TPalavra criarPalavra(char* texto);



#endif // TPALAVRA_H