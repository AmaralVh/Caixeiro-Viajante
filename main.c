#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
#include "pilha.h"


int main() {
    int quantidade;        // Quantidade de cidades
    int inicial;           // Cidade inicial
    lista *list;           // Lista (TAD) que guardara as cidades e suas insformacoes

    // Recebe a quantidade de cidades e a cidade inicial:
    scanf("%d %d", &quantidade, &inicial);

    // Cria a lista para armazenar as cidades e suas informacoes:
    list = cria_lista(quantidade);

    int cidade1, cidade2;
    int distancia;

    // Recebe toda a entrada e forma a lista com as informacoes de todas as cidades,
    // seus respectivos vizinhos e as distancias entre ambos:
    while(scanf("%d %d %d", &cidade1, &cidade2, &distancia) != EOF) {
        insere_vizinho(list, criar_item(cidade1), criar_item(cidade2), distancia);
    }

    // Chama a funcao de forca bruta, que ira testar todos os caminhos 
    // e printara o caminho de menor custo entre as cidades:
    forca_bruta(list, inicial, quantidade);  // Funcao implementada no TAD lista
    
    return 0;
}