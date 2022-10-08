#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

typedef struct vizinho_v { 
	item *cidade;         // vizinho
    int distancia;		  // distancia do vizinho ate a cidade
} vizinho;

struct lista_t {
	item *cidade;         // cidade 
    vizinho vizinhos[12]; // vetor de vizinhos dessa cidade
	int totalVizinhos;    // total de vizinhos dessa cidade
};


lista *cria_lista(int quantidade) {
	// Aloca memoria para a lista de acordo com a quantidade passada pelo
	// usuario (quantidade de cidades):
    lista *l = (lista *)malloc((quantidade+1) * sizeof(lista));
	if (l == NULL) {
		return NULL;
	}

	// Atribui todas as cidades e define o total de vizinhos como 0 para
	// todas elas:
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

	// Guarda valor de cada cidade em 'i1' e 'i2':
	int i1 = get_valor(cidade1);
	int i2 = get_valor(cidade2);

	// Incrementa o total de vizinhos de cada cidade:
	l[i1].totalVizinhos++;
	l[i2].totalVizinhos++;
	int totVizinhos1 = l[i1].totalVizinhos;
	int totVizinhos2 = l[i2].totalVizinhos;

	// Define os novos vizinhos para cada uma das cidades
	// (repare que uma e vizinha da outra, isto e, relacao mutua)
	// e tambem define a distancia entre esses vizinhos:
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

int retornou_inicio(int totalViajado, int quantidade) {
	if(totalViajado == quantidade) {

	}
	else {
		return 0;
	}
}

//transformando saida em int
int cidade_atual(pilha *visitados){
	item *t = criar_item(0);
	top(visitados, &t);
	int i = get_valor(t);

	return i;
}

int* percorre(lista *l, pilha *visitados, int *melhor_caminho, int *distancia, int menor_distancia, int inicial, int quantidade, int vizinho){
	// criou item e pego a atual cidade
	
	int atual = cidade_atual(visitados);
	
	while(vizinho < l[atual].totalVizinhos) {
		if(verificando(visitados, l[atual].vizinhos[vizinho].cidade) == 0) {
			push(visitados, l[atual].vizinhos[vizinho].cidade);
			break;
		}
		else {
			vizinho++;
		}
	}
	
	*distancia++;

	atual = cidade_atual(visitados);

	if(atual == inicial && (*distancia) == quantidade) {
		if((*distancia) < menor_distancia) {
			// gravar_melhor_caminho();
		}
		//backtracking();
	}
	else {
		percorre(l, visitados, melhor_caminho, distancia, menor_distancia, inicial,  quantidade,  vizinho);
	}

}

void forca_bruta(lista *l, int inicial, int quantidade) {
	pilha *visitados;
	int *melhor_caminho; 
	int menor_distancia;
	int distancia = 0;
	int vizinho = 1;
	

	// criando pilha e colocando a origem
	visitados = criar_pilha();
	push(visitados,criar_item(inicial));
	melhor_caminho = (int*) malloc((quantidade+1) * sizeof(int));

	percorre(l, visitados, melhor_caminho, &distancia, menor_distancia, inicial, quantidade, vizinho);

}