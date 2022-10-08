#ifndef _LISTA_H
#define _LISTA_H

#include "item.h"


typedef struct lista_t lista;

lista *cria_lista(int quantidade);

void insere_vizinho(lista *l, item *cidade1, item *cidade2, int distancia);

void insere_cidade(lista *l, item *cidade1);

item *get_cidade(lista *l, int i);

int get_totVizinho(lista *l,int i);

item *get_vizinhos(lista *l, int i, int j);

int get_distancia(lista *l, int i, int j);

void forca_bruta(lista *l, int inicial, int quantidade);

int cidade_atual(pilha *visitados);

int* percorre(lista *l, pilha *visitados, int *melhor_caminho, int *distancia, int menor_distancia, int inicial, int quantidade, int vizinho);

#endif