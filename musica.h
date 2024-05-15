#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseneutra.h"
#include "pilha.h"
#include "fila.h"

typedef struct musica t_musica;
void remover_inicio_musica();
void imprimir_musica(void *m1);
t_musica* criar_musica(char nome[], char genero[], int duracao);
int comparar_musica(t_musica *m1, t_musica *m2);