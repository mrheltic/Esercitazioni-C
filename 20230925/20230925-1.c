//
// Created by mrheltic on 12/07/24.
//
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num){
    if(num <= 1){
        return false;
    }
    for (int i = 2; i + 1 <= num; i++){
        if (num % i == 0){
            return false;
        }
    }
}

int main(){
    int inizio, fine;
    printf("Inserisci il numero di inizio: ");
    scanf("%d", &inizio);
    printf("Inserisci il numero di inizio: ");
    scanf("%d", &fine);

    if( inizio<0 || fine <0 || inizio>fine){
        printf("Errore: input non valido.\n");
        return 1;
    }

    for (int i = inizio; i <= fine; i++){
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}