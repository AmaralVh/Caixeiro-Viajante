#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

// Struct de cada vizinho:
typedef struct vizinho_v { 
	item *cidade;         // vizinho
    int distancia;		  // distancia do vizinho ate a cidade
} vizinho;

// Struct de cada cidade:
struct lista_t {
	item *cidade;         // cidade 
    vizinho vizinhos[12]; // vetor de vizinhos dessa cidade
	int totalVizinhos;    // total de vizinhos dessa cidade
};


lista *cria_lista(int quantidade) {
	/* Aloca memoria para a lista de acordo com a quantidade passada pelo
	usuario (quantidade de cidades):*/

    lista *l = (lista *)malloc((quantidade+1) * sizeof(lista));
	if (l == NULL) {
		return NULL;
	}

	/*Atribui todas as cidades e define o total de vizinhos de cada uma 
	como 0 para todas elas: */
	for(int i = 1; i <= quantidade; i++) {
		l[i].cidade = criar_item(i);
		l[i].totalVizinhos = 0;
	}

	return l;
}


void exclui_lista(lista **l, int quantidade) {
	if((*l) == NULL) {
		exit(1);
	}

	/* apaga item por item para depois excluir a fila*/
	for(int i = 1; i <= quantidade; i++) {
		for(int j = 1; j <= l[i]->totalVizinhos; i++) {
			apagar_item(&(l[i]->vizinhos[j].cidade));
		}
		apagar_item(&(l[i]->cidade));
	}

	free(*l);
	*l = NULL;
}


void insere_vizinho(lista *l, item *cidade1, item *cidade2, int distancia) {
	if (l == NULL) {
		exit(1);
	}

	// Guarda cada cidade em 'i1' e 'i2':
	int i1 = get_valor(cidade1);
	int i2 = get_valor(cidade2);

	// Incrementa o total de vizinhos de cada cidade:
	l[i1].totalVizinhos++;
	l[i2].totalVizinhos++;
	int totVizinhos1 = l[i1].totalVizinhos;
	int totVizinhos2 = l[i2].totalVizinhos;

	/*Define os novos vizinhos para cada uma das cidades
	(repare que uma eh vizinha da outra, isto e, relacao mutua)
	e tambem define a distancia entre esses vizinhos*/
	l[i1].vizinhos[totVizinhos1].cidade = cidade2;
	l[i1].vizinhos[totVizinhos1].distancia = distancia;
	l[i2].vizinhos[totVizinhos2].cidade = cidade1;
	l[i2].vizinhos[totVizinhos2].distancia = distancia;

}


//verfificando cidade atual e retornando ela
int cidade_atual(pilha *visitados){
	item *t = criar_item(0);
	top(visitados, &t);
	int i = get_valor(t);
	apagar_item(&t);

	return i;
}

// função percorre funciona como um Backtracking
void percorre(lista *l, pilha *visitados, int **melhor_caminho, int *distancia, int *menor_distancia, int inicial, int quantidade, int atual){
	int vizinho = 1;

	//condição para nao deixar que o percurso termine antes de passar em todas as cidades
	if(atual == inicial && tam_pilha(visitados) > 0) {
		if(tam_pilha(visitados) == quantidade) {	// se passou em todas as cidades return
		
			if(*distancia < *menor_distancia) { // comparação de caminho
				*menor_distancia = *distancia;
				*melhor_caminho = pilha_vetor(visitados); // transformando a pilha em vetor
			}
		}
		return;
	}

	while(vizinho <= l[atual].totalVizinhos) {
		
		//verifica se a cidade ja foi passada
		if(contem(visitados, l[atual].vizinhos[vizinho].cidade) == 0) {

			//percorrendo e adicionando distancia 
			push(visitados, l[atual].vizinhos[vizinho].cidade);
			int proxViz = get_valor(l[atual].vizinhos[vizinho].cidade);
			*distancia = *distancia + l[atual].vizinhos[vizinho].distancia;
			percorre(l, visitados, melhor_caminho, distancia, menor_distancia, inicial, quantidade, get_valor(l[atual].vizinhos[vizinho].cidade));
			
			//volta do backtracking desempilhando visitados
			item *t;
			pop(visitados, &t);
			*distancia = *distancia - l[atual].vizinhos[vizinho].distancia;
			
		}

		vizinho++;
	}

	return;
}


void forca_bruta(lista *l, int inicial, int quantidade) {
	pilha *visitados;
	int *melhor_caminho; 
	int menor_distancia = 12000;
	int distancia = 0;	

	// criando pilha e colocando a origem
	visitados = criar_pilha();
	// push(visitados,criar_item(inicial));
	melhor_caminho = (int*) malloc((quantidade+1) * sizeof(int));

	percorre(l, visitados, &melhor_caminho, &distancia, &menor_distancia, inicial, quantidade, inicial);

	destruir_pilha(&visitados);
	// exclui_lista(&l, quantidade);

	// print do melhor caminho
	printf("%d ", inicial);
	for(int i = 1; i <= quantidade; i++) {
		printf("%d ", melhor_caminho[i]);
	}
}