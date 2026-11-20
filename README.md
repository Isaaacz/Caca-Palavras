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
- `Tbusca` — módulo de busca que centraliza a lógica de procura na matriz

## Exemplo de uso

Entrada (a matriz é digitada linha por linha, sem espaços entre as letras):

```
4 4
casa
obol
lode
alob
4
casa
cola
bola
sol
```

Saída:

```
casa: (0,0) -> (0,3)
cola: (0,0) -> (3,0)
bola: (3,3) -> (3,0)
sol: (0,0)
```

As coordenadas são `(linha,coluna)`, começando em 0. `cola` foi encontrada na vertical e `bola` de trás pra frente na última linha. Quando a palavra não está na matriz, o programa imprime `(0,0)`.

## ▶️ Como compilar

```bash
gcc -Wall main.c Tmatriz.c Tcoordenada.c Tpalavra.c TlistaPalavras.c Tbusca.c -o caca-palavras
./caca-palavras
```
