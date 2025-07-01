# Caça-Palavras em C 🧩

Este projeto implementa um jogo de caça-palavras utilizando a linguagem C, com foco na aplicação de Tipos Abstratos de Dados (TADs), modularização de código e alocação dinâmica de memória. O programa permite que o usuário digite uma matriz de letras e uma lista de palavras, realizando a busca de cada uma em todas as direções possíveis dentro da matriz.

## 🛠️ Funcionalidades

- Leitura da matriz de letras digitada pelo usuário
- Leitura da lista de palavras a serem buscadas
- Busca em todas as 8 direções (horizontal, vertical e diagonais)
- Indicação da posição de início e fim de cada palavra encontrada
- Estrutura de código dividida em módulos (`.h` e `.c`)

## 📁 Estrutura de TADs

- `Tmatriz` — representa a matriz de caracteres do caça-palavras
- `Tcoordenada` — representa uma posição (linha, coluna)
- `Tpalavra` — representa uma palavra buscada, com início, fim e status
- `TlistaPalavras` — armazena a lista de palavras fornecidas pelo usuário
- *(opcional)* `Tbusca` — módulo de busca que centraliza a lógica de procura na matriz

## ▶️ Como compilar

Você pode compilar o projeto com `gcc` manualmente:

```bash
gcc main.c Tmatriz.c Tcoordenada.c Tpalavra.c TlistaPalavras.c -o caca-palavras
./caca-palavras
