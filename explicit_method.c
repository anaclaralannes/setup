#include "functions.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <omp.h> 

// Função que "pega" o x, y, u e salva seus respectivos valores num arquivo em forma de tabela ao decorrer do tempo
void save_to_file(double **u, double dx, double dy, int time_step) {
    int i, j;
    char filename[64];
    FILE *file;

    sprintf(filename, "output_timestep_%04d.txt", time_step);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "#\t--x--\t\t--y--\t\t-u(x,y,t)-\n\n");

    for (i = 0; i < N + 2; i++) {
        for (j = 0; j < M + 2; j++)
            fprintf(file, "%f\t%f\t%f\n", dx * i, dy * j, u[i][j]);
        fprintf(file, "\n");
    }

    fclose(file);
}


// Função para aplicar o método explícito para resolver a equação do calor
void explicit_method(double **u, double dx, double dy, double dt, int save_interval) {
    int i, j, t;
    double alpha, beta, a;
    double **u_old;

    u_old = (double **)malloc((N + 2) * sizeof(double *));
    for (i = 0; i < N + 2; i++)
        u_old[i] = (double *)malloc((M + 2) * sizeof(double));

    alpha = (dt * D) / (dx * dx);
    beta = (dt * D) / (dy * dy);

    a = 1 - 2 * alpha - 2 * beta;

    for (t = 0; t < T; t++) {
        // Copia o conteúdo da matriz u para u_old usando um loop aninhado
        for (i = 0; i < N + 2; i++) {
            for (j = 0; j < M + 2; j++) {
                u_old[i][j] = u[i][j];
            }
        }

        #pragma omp parallel for private(i,j) // diretiva do OpenMP para paralelizar o loop
        for (j = 1; j < M + 1; j++)
            for (i = 1; i < N + 1; i++)
                u[i][j] = alpha * u_old[i + 1][j] + beta * u_old[i][j + 1] + a * u_old[i][j] + alpha * u_old[i - 1][j] + beta * u_old[i][j - 1];

        // Aplica as condições de contorno (assumindo temperatura constante nos contornos)
        for (j = 0; j < M + 2; j++) {
            u[0][j] = Tf;
            u[N + 1][j] = Tf;
        }
        for (i = 0; i < N + 2; i++) {
            u[i][0] = Tf;
            u[i][M + 1] = Tf;
        }

        if (t % save_interval == 0) {
            save_to_file(u, dx, dy, t);
        }
    }

    free(u_old);

    return;
}
