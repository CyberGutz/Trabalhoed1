all:
	clear
	gcc ./src/main.c ./src/porto.h ./src/porto.c ./src/fila.c ./src/pilha.c -o ./obj/sim

run:
	clear 
	gcc ./src/main.c ./src/porto.h ./src/porto.c ./src/fila.c ./src/pilha.c -o ./obj/sim
	./obj/sim

clean:
	clear
	rm ./obj/sim
	
cleanmake:
	clear
	rm ./obj/sim
	gcc ./src/porto.h ./src/porto.c ./src/fila.c ./src/pilha.c ./src/main.c -o ./obj/sim

cleanrun:
	clear
	rm ./obj/sim
	gcc ./src/porto.h ./src/porto.c ./src/fila.c ./src/pilha.c ./src/main.c -o ./obj/sim
	./obj/sim