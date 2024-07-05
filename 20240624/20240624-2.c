//
// Created by mrheltic on 02/07/2024.
//

#include <stdio.h>

// Funzione ricorsiva per calcolare x elevato alla e
int potenza_ricorsiva(int x, int e) {
    // Caso base: se e è 0, restituisci 1
    if (e == 0) {
        return 1;
    }
    // Caso ricorsivo: moltiplica x per il risultato di x elevato alla e-1
    else {
        return x * potenza_ricorsiva(x, e - 1);
    }
}

// Funzione iterativa per calcolare x elevato alla e
int potenza_iterativa(int x, int e) {
    // Inizia con un risultato di 1
    int risultato = 1;

    // Moltiplica il risultato per x per e volte
    for (int i = 0; i < e; i++) {
        risultato *= x;
    }

    // Restituisci il risultato
    return risultato;
}

int main() {
    int x = 2;
    int e = 10;

    int risultato_ricorsivo = potenza_ricorsiva(x, e);
    printf("Risultato ricorsivo: %d\n", risultato_ricorsivo);

    int risultato_iterativo = potenza_iterativa(x, e);
    printf("Risultato iterativo: %d\n", risultato_iterativo);

    return 0;
}
