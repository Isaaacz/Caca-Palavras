#ifndef TBUSCA_H
#define TBUSCA_H

#include "Tmatriz.h"
#include "Tpalavra.h"
#include "TlistaPalavras.h"

void buscarTodasPalavras(TMatriz* matriz, TListaPalavras* lista);

int buscarPalavra(TMatriz* matriz, TPalavra* palavra);

int verificarPalavraDirecao(TMatriz* matriz, TPalavra* palavra, int linha, int coluna, int deltaLinha, int deltaColuna);

#endif
