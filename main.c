#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
#include "pilha.h"


int main() {
    int quantidade;
    int inicial;
    int ultimaCidade = 0;
    lista *list;

    scanf("%d %d", &quantidade, &inicial);

    list = cria_lista(quantidade);

    int cidade1, cidade2;
    int distancia;

    // Recebe toda a entrada e forma o "grafo" com as informacoes de todas as cidades,
    // seus respectivos vizinhos e as distancias entre ambos:
    while(scanf("%d %d %d", &cidade1, &cidade2, &distancia) != EOF) {
        insere_vizinho(list, criar_item(cidade1), criar_item(cidade2), distancia);
    }

    forca_bruta(list, inicial, quantidade);
    
    return 0;
}