CC = gcc
CFLAGS = -Wall -std=c99 -fopenmp
OBJ = main.o inicializa_matriz.o condicao_inicial.o explicit_method.o 
EXE = diffusion

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c constants.h functions.h
	$(CC) $(CFLAGS) -c $<

inicializa_matriz.o: inicializa_matriz.c constants.h functions.h 
	$(CC) $(CFLAGS) -c $<

condicao_inicial.o: condicao_inicial.c constants.h functions.h
	$(CC) $(CFLAGS) -c $<

explicit_method.o: explicit_method.c constants.h functions.h 
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(OBJ) $(EXE) output_timestep_*.txt

.PHONY: all clean


