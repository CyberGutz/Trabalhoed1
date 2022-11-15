all:
	clear
	gcc ./src/porto.h ./src/porto.c ./src/fila.c ./src/pilha.c ./src/main.c -o ./obj/sim

run:
	clear 
	gcc ./src/porto.h ./src/porto.c ./src/fila.c ./src/pilha.c ./src/main.c -o ./obj/sim
	./sim

clean:
	clear
	rm sim
	
cleanmake:
	clear
	rm sim
	gcc ./src/porto.h ./src/porto.c ./src/fila.c ./src/pilha.c ./src/main.c -o ./obj/sim

cleanrun:
	clear
	rm sim
	gcc ./src/porto.h ./src/porto.c ./src/fila.c ./src/pilha.c ./src/main.c -o ./obj/sim
	./sim