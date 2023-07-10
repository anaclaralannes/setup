#include "functions.h"

// Função para inicializar a matriz u com a temperatura inicial Tf
void inicializa_matriz(double **u) {
    int i, j;
    double temp = Tf;

    for (j = 0; j < M + 2; j++)
        for (i = 0; i < N + 2; i++)
            u[i][j] = temp;

    return;
}
