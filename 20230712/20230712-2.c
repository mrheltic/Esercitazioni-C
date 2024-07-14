//
// Created by mrheltic on 13/07/24.
//
#include <stdio.h>
#include <stdlib.h>

void initialize_array(int* arr, int size){
    printf("Inserisci i valori degli elementi dell'array:\n");
    for (int i = 0; i < size; i++){
        printf("Elemento %d: ", i);
        scanf("%d", &arr[i]);
    }
}

int calcola_somma(int* arr, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum;
}

int find_maximum(int* arr, int size){
    int max = arr[0];
    for (int i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

void display_array(int* arr, int size){
    printf("Visualizza i valori dell'array:\n");
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
    printf("\n");
}


int main(){
    int size;
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    initialize_array(arr, size);

    int sum = calcola_somma(arr, size);
    printf("La somma degli elementi dell'array e': %d\n",sum);

    int max = find_maximum(arr, size);
    printf("L'elemento massimo dell'array e': %d\n", max);

    display_array(arr, size);

    free(arr);

    return 0;
}