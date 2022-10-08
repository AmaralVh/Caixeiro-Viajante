#ifndef _PILHA_H
#define _PILHA_H

#include "item.h"

#define TAM_PILHA 13

typedef struct pilha_p pilha;

pilha *criar_pilha();
int push(pilha *p, item *x);
int pop(pilha *p, item **x);
int top(pilha *p, item **x);
int isFull(pilha *p);
int isEmpty(pilha *p);
void destruir_pilha(pilha **p);
int verificando(pilha*p, item *x);

#endif