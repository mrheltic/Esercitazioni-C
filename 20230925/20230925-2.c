//
// Created by mrheltic on 12/07/24.
//
#include <stdio.h>

int fibonacci(int n){
    if (n == 0){
        return 0;
    }

    if (n == 1){
        return 1;
    }

    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    int n;
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &n);

    if (n < 0){
        printf("Errore: input non valido. \n");
        return 1;
    }

    int result = fibonacci(n);

    printf("Il %d* numero di FIbonacci e': %d\n", n, result);

    return 0;
}