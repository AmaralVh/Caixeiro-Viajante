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

#endif