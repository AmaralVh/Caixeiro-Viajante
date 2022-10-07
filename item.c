#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct _item {
	elem valor;
};

item *criar_item(elem x) {
	item *p = (item *)malloc(sizeof(item));
	if(p != NULL) {
		p->valor = x;
		return p;
	}
	return NULL;
}

void set_valor(item *e, elem x) {
	if(e != NULL) {
		e->valor = x;
	}
}

elem get_valor(item *e) {
	if(e != NULL) {
		return e->valor;
	}
	exit(1); 
}

void apagar_item(item **e) {
	if(e != NULL && *e != NULL) {
		free(*e);
		*e = NULL;
	}	
}