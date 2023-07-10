#include "functions.h"

// Função para aplicar a condição inicial de uma circunferência com temperatura Tq
void condicao_inicial(double **u, double dx, double dy) {
    int i, j;
    int cx, cy, r, r2; // Centro x, y e raio da circunferência
    double a, b, p;
    double temp = Tq;

    // Definição da circunferência
    cx = L / 2.0;
    cy = A / 2.0;
    r = 2.0;
    r2 = r * r;

    // Aplicação da condição inicial
    for (i = 1; i < N + 2; i++)
        for (j = 1; j < M + 2; j++) {
            a = (i * dx - cx);
            b = (j * dy - cy);
            p = a * a + b * b;

            if (p < r2)
                u[i][j] = temp;
        }

    return;
}
