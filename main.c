#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"


int main() {
    int quantidade;
    int inicial;
    int ultimaCidade = 0;
    lista *list;

    scanf("%d %d", &quantidade, &inicial);

    list = cria_lista(quantidade);

    int cidade1, cidade2;
    int distancia;

    while(scanf("%d %d %d", &cidade1, &cidade2, &distancia) != EOF) {
        insere_vizinho(list, criar_item(cidade1), criar_item(cidade2), distancia);
    }

    for(int i = 1; i <= quantidade; i++) {
        item *t = get_cidade(list, i);
        
        printf("Cidade: %d distancia:", get_valor(t));
        int tot = get_totVizinho(list, i);
        for(int j = 1; j <= tot; j++) {
            //item *d = get_vizinhos(list, i, j);
            printf(" %d %d |", get_valor(get_vizinhos(list, i, j)) ,get_distancia(list, i, j));
        }
        printf("\n");
    }
    

    return 0;
}