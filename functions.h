//Interface que define as funções necessárias para fazer as operações na main.
#pragma once

#include "constants.h"

void inicializa_matriz(double **u);
void condicao_inicial(double **u, double dx, double dy);
void explicit_method(double **u, double dx, double dy, double dt, int save_interval);
