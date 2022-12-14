all: item.o pilha.o lista.o main.o
	gcc item.o pilha.o lista.o main.o -o caixeiro -std=c99 -Wall
	
item.o: 
	gcc -c item.c -o item.o

pilha.o: 
	gcc -c pilha.c -o pilha.o

lista.o: 
	gcc -c lista.c -o lista.o

main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o caixeiro

run:
	./caixeiro