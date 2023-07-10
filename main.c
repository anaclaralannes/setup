#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "constants.h"

// Função principal que chama todas as outras funções
int main() {
    double **u; // Matriz solução numérica
    double dx, dy, dt;
    int i,save_interval = 100;

	
	u =  (double**)malloc((N+2)*sizeof(double*));
	for(i=0;i<N+2;i++) 
		u[i] = (double*)malloc((M+2)*sizeof(double));
	
    dx = L / (N + 2); // Cálculo do tamanho do intervalo dx
    dy = A / (M + 2); // Cálculo do tamanho do intervalo dy
    dt = ((dx*dx)*(dy*dy)) / (2 * D *((dx*dx)+(dy*dy))); // Cálculo do intervalo de tempo dt


    // Inicialização da matriz u com a temperatura inicial
    inicializa_matriz(u);
   
    // Aplicação da condição inicial em uma circunferência
    condicao_inicial(u, dx, dy);

    // Aplicação do método explícito para resolver a equação do calor
    explicit_method(u, dx, dy, dt, save_interval);
   
    free(u);

    return 0;
}
