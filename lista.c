#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct vizinho_v { 
	item *cidade;         // vizinho
    int distancia;		  // distancia do vizinho ate a cidade
} vizinho;

struct lista_t {
	item *cidade;         // cidade 
    vizinho vizinhos[12];    // vetor de vizinhos dessa cidade
	int totalVizinhos;    // total de vizinhos dessa cidade
};


lista *cria_lista(int quantidade) {
    lista *l = (lista *)malloc((quantidade+1) * sizeof(lista));
	if (l == NULL) {
		return NULL;
	}

	for(int i = 1; i <= quantidade; i++) {
		l[i].cidade = criar_item(i);
		l[i].totalVizinhos = 0;
	}

	return l;
}

void insere_vizinho(lista *l, item *cidade1, item *cidade2, int distancia) {
	if (l == NULL) {
		exit(1);
	}
	int i1 = get_valor(cidade1);
	int i2 = get_valor(cidade2);

	//adicionando no total de vizinhos
	l[i1].totalVizinhos++;
	l[i2].totalVizinhos++;
	int totVizinhos1 = l[i1].totalVizinhos;
	int totVizinhos2 = l[i2].totalVizinhos;

	//colocando id do vizinho
	l[i1].vizinhos[totVizinhos1].cidade = cidade2;
	l[i1].vizinhos[totVizinhos1].distancia = distancia;
	l[i2].vizinhos[totVizinhos2].cidade = cidade1;
	l[i2].vizinhos[totVizinhos2].distancia = distancia;

}

item *get_cidade(lista *l, int i) {
	if (l == NULL) {
		return NULL;
	}

	return l[i].cidade;
}

int get_totVizinho(lista *l,int i) {
	if (l == NULL) {
		exit (1);
	}

	return l[i].totalVizinhos;
}

item *get_vizinhos(lista *l, int i, int j) {
	if (l == NULL) {
		exit(1);
	}

	return l[i].vizinhos[j].cidade;
}

int get_distancia(lista *l, int i, int j) {
	if (l == NULL) {
		exit(1);
	}

	return l[i].vizinhos[j].distancia;
}