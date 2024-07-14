//
// Created by mrheltic on 12/07/24.
//
#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;

    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL){
        printf("Memoria non allocata\n");
        exit(0);
    }

    printf("Inserisci i valori degli elementi dell'array:\n");
    for( int i = 0; i < size; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("La somma degli elementi dell'array e': %d\n",sum);

    free(arr);
    return 0;
}