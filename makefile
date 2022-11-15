all:
	clear
	gcc porto.h fila.h pilha.h porto.c fila.c pilha.c main.c -o sim

run:
	clear 
	gcc porto.h fila.h pilha.h porto.c fila.c pilha.c main.c -o sim
	./sim

clean:
	clear
	rm sim
	
cleanmake:
	clear
	rm sim
	gcc porto.h fila.h pilha.h porto.c fila.c pilha.c main.c -o sim

cleanrun:
	clear
	rm sim
	gcc porto.h fila.h pilha.h porto.c fila.c pilha.c main.c -o sim
	./sim