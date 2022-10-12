#ifndef _LISTA_H
#define _LISTA_H

#include "item.h"
#include "pilha.h"


typedef struct lista_t lista;

lista *cria_lista(int quantidade);

void insere_vizinho(lista *l, item *cidade1, item *cidade2, int distancia);

void exclui_lista(lista **l, int quantidade);

void forca_bruta(lista *l, int inicial, int quantidade);

int cidade_atual(pilha *visitados);

void percorre(lista *l, pilha *visitados, int **melhor_caminho, int *distancia, int *menor_distancia, int inicial, int quantidade, int atual);

#endif