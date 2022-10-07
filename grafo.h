#ifndef GRAFO_H
#define GRAFO_H

#include <stdbool.h>
#include "item.h"

struct no {
	item_t *cidade;
	item_t *peso_cidade;
	no_t *prox;
};

struct lista {
	no_t *ini, *fim;
	int total;
};


#endif