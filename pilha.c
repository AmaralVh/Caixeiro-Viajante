#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "item.h"

struct pilha_p {
	int topo;
	item *itens[TAM_PILHA];
};

pilha *criar_pilha() {
	pilha *p = (pilha *)malloc(sizeof(pilha));
	if(p == NULL) {
		return NULL;
	}
	p->topo = -1;
	return p;
}

int push(pilha *p, item *x) {
	if(p == NULL) {
		exit(1);
	}
	if(!isFull(p)) {
		p->topo += 1;
		p->itens[p->topo] = x;
		return 1;
	}
	return 0;
}

int pop(pilha *p, item **x) {
	if(top(p, x)) {
		p->topo -= 1;
		return 1;
	}
	
	return 0;
}

int top(pilha *p, item **x) {
	if(p == NULL) {
		exit(1);
	}
	if(!isEmpty(p)) {
		*x = p->itens[p->topo];
		return 1;
	}
	return 0;
}

int isFull(pilha *p) {
	if(p == NULL) {
		exit(1);
	}
	if(p->topo == TAM_PILHA - 1) {
		return 1; 
	}
	return 0;
}

int isEmpty(pilha *p) {
	if(p == NULL) {
		exit(1);
	}
	if(p->topo == -1) {
		return 1; 
	}
	return 0;
}

void destruir_pilha(pilha **p) {
	if(*p != NULL) {
		free(*p);
		*p = NULL;
	}
}

//funcao verificando se cidade ja foi passada
int verificando(pilha*p, item *x){
	int achou = 0;
	item *saida = criar_item(0);
	pilha *pilha_aux = criar_pilha();
	
	//verificando igualdade e passando pra pilha aux
	do {
		pop(p, &saida);
		push(pilha_aux, saida);
		if(get_valor(saida) == get_valor(x)) {
			achou = 1;
			break;
		}
	}while(isEmpty(p) == 1);

	//pilha aux devolve
	do {
		pop(pilha_aux, &saida);
		push(p, saida);
	}while(isEmpty(pilha_aux) == 1);

	apagar_item(&saida);
	destruir_pilha(&pilha_aux);

	return achou;
}