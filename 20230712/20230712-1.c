//
// Created by mrheltic on 13/07/24.
//
#include <stdio.h>

int main(){
    const int MAX_SIZE = 10;

    int D;
    do {
        printf("Inserisci la dimensione della matrice (<= 10): ");
        scanf("%d", &D);
    } while (D > MAX_SIZE);

    int matrix[D][D];

    printf("Inserisci i valori delle celle della matrice: \n");
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < D; j++){
            printf("Inserisci il valore della cella [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int isSymmetric = 1;
    for (int i = 0; i < D; i++){
        for (int j = 0; j < i; j++){
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }

        if (!isSymmetric){
            break;
        }
    }

    if (isSymmetric){
        printf("La matrice e' simmetrica.\n");
    } else{
        printf("La matrice NON e' simmetrica.\n");
    }

    return 0;
}