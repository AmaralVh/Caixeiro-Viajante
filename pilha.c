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

int tam_pilha(pilha *p) {
	return (p->topo + 1);
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
int contem(pilha*p, item *x){
	for(int i = 0; i <= p->topo; i++) {
		if(get_valor(x) == get_valor(p->itens[i])) {
			return 1;
		}
	}

	return 0;
}

int *pilha_vetor(pilha *visitados) {
	int *vetor = (int *) malloc(sizeof(int) * (tam_pilha(visitados) + 1));
	int i = tam_pilha(visitados);
	int quantidade = i; // apagar isso dps

	for(int i = 0; i <= visitados->topo; i++) {
		vetor[i+1] = get_valor(visitados->itens[i]);
	}

	return vetor;
}