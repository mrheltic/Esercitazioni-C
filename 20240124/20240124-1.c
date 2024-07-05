//
// Created by mrheltic on 04/07/2024.
//
#include <stdio.h>

// Procedura per comprimere un segnale
void compress_signal(float* V, int L) {
    // Chiedi all'utente di inserire un valore intero N che sia un divisore di L
    int N;
    do {
        printf("Inserisci un valore intero N che sia un divisore di %d: ", L);
        scanf("%d", &N);
    } while (L % N != 0);

    // Calcola la lunghezza del nuovo vettore
    int new_length = L / N;

    // Crea il nuovo vettore
    float VC[new_length];

    // Comprimi il segnale
    for (int i = 0; i < new_length; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += V[i * N + j];
        }
        VC[i] = sum / N;
    }

    // Stampa il contenuto del nuovo vettore
    printf("Il vettore compresso e':\n");
    for (int i = 0; i < new_length; i++) {
        printf("%.2f ", VC[i]);
    }
    printf("\n");
}

int main() {
    // Crea un vettore di numeri reali
    float V[] = {2.3, 2.6, 3.2, 2.5, 2.8, 2.2};
    int L = sizeof(V) / sizeof(V[0]);

    // Comprimi il segnale
    compress_signal(V, L);

    return 0;
}
