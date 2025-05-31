#ifndef TLISTAPALAVRAS_H
#define TLISTAPALAVRAS_H

#include "TPalavra.h"

typedef struct TListaPalavras {
    TPalavra *palavras;
    int quantidade;
} TListaPalavras;

TListaPalavras* criarListaPalavras(int quantidade);
void preencherListaPalavras(TListaPalavras* lista);
void liberarListaPalavras(TListaPalavras* lista);
void imprimirResultadosListaPalavras(TListaPalavras* lista);

#endif