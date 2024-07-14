//
// Created by mrheltic on 05/07/24.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM_FISICA 100

int max_somma_riga = 0;
int max_somma_colonna = 0;
int somma_diagonale = 0;

void calcola_somme(int matrice[DIM_FISICA][DIM_FISICA], int N) {
    for (int i = 0; i < N; i++){
        int somma_riga = 0;
        int somma_colonna = 0;

        for (int j = 0; j < N; j++){
            somma_riga += matrice[i][j];
            somma_colonna += matrice[j][i];
            if (i == j){
                somma_diagonale += matrice[i][j];
            }
        }

        if (somma_riga > max_somma_riga){
            max_somma_riga = somma_riga;
        }

        if (somma_colonna > max_somma_colonna){
            max_somma_colonna = somma_colonna;
        }
    }

    printf(" La piu' grande somma degli elementi di una riga e': %d\n", max_somma_riga);
    printf(" La piu' grande somma degli elementi di una colonna e': %d\n", max_somma_colonna);
    printf(" La piu' grande somma degli elementi di una diagonale e': %d\n", somma_diagonale);
}

int main (){
    int matrice[DIM_FISICA][DIM_FISICA];

    for (int i = 0; i < DIM_FISICA; i++){
        for (int j = 0; j < DIM_FISICA; j++){
            matrice[i][j] = rand() % 100;
        }
    }

    int N;
    printf("Inserisci la dimensione logica N (<= 100): ");
    scanf("%d", &N);

    calcola_somme(matrice, N);

    return 0;
}