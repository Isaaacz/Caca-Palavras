#include <string.h>
#include "TPalavra.h"
#include "Tcoordenada.h"

// Função para criar e inicializar uma nova palavra
TPalavra criarPalavra(char* texto) {

    TPalavra p;
    strcpy(p.palavra, texto); // Copia o texto fornecido para o campo 'palavra'
    p.encontrada = 0;

    // Inicializa as coordenadas de início e fim como inválidas
    p.inicio = criarCoordenada(-1, -1);
    p.fim = criarCoordenada(-1, -1);

    return p;
}