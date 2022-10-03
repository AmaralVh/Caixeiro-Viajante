#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>
#include "item.h"

typedef struct lista lista_t; 

lista_t *cria_lista();
void libera_lista(lista_t **l);
void insere(lista_t *l, item_t *x, item_t *y);
int tamanho(lista_t *l);
bool esta_na_lista(lista_t *l, elem x);
//void imprimir(lista_t *l);
void remover(lista_t *l, elem x);

#endif