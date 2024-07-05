//
// Created by mrheltic on 02/07/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM_FISICA 100

    int max_somma_riga = 0;
int max_somma_colonna = 0;
int somma_diagonale = 0;

// Calcola le somme per ogni riga e colonna, e la somma sulla diagonale
// Funzione per calcolare e stampare le somme richieste
void calcola_somme(int matrice[DIM_FISICA][DIM_FISICA], int N) {
    for (int i = 0; i < N; i++) {
        int somma_riga = 0;
        int somma_colonna = 0;
        for (int j = 0; j < N; j++) {
            somma_riga += matrice[i][j];
            somma_colonna += matrice[j][i];
            if (i == j) {
                somma_diagonale += matrice[i][j];
            }
        }
        if (somma_riga > max_somma_riga) {
            max_somma_riga = somma_riga;
        }
        if (somma_colonna > max_somma_colonna) {
            max_somma_colonna = somma_colonna;
        }
    }

    // Stampa le somme calcolate
    printf("La piu' grande somma degli elementi di una riga e': %d\n", max_somma_riga);
    printf("La piu' grande somma degli elementi di una colonna e': %d\n", max_somma_colonna);
    printf("La somma degli elementi sulla diagonale e': %d\n", somma_diagonale);
}

int main() {
    srand(time(NULL));

    // Crea e popola la matrice con numeri casuali
    int matrice[DIM_FISICA][DIM_FISICA];
    for (int i = 0; i < DIM_FISICA; i++) {
        for (int j = 0; j < DIM_FISICA; j++) {
            matrice[i][j] = rand() % 100;
        }
    }

    // Chiedi all'utente di inserire la dimensione logica N
    int N;
    printf("Inserisci la dimensione logica N (<= 100): ");
    scanf("%d", &N);

    // Calcola e stampa le somme richieste
    calcola_somme(matrice, N);

    return 0;
}