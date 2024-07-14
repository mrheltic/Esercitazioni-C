//
// Created by mrheltic on 14/07/24.
//
#include <stdio.h>
#include <string.h>

int main(){
    char category[41];
    float minPrice, maxPrice;

    printf("Inserisci la categoria: ");
    scanf("%s", category);

    printf("Inserisci il prezzo minimo: ");
    scanf("%f", &minPrice);

    printf("Inserisci il prezzo massimo: ");
    scanf("%f", &maxPrice);

    FILE* file = fopen("20220613/prodotti.txt","r");
    if (file == NULL){
        printf("Impossibile aprire il file\n");
        return 1;
    }

    char prodName[41], prodCategory[41];
    float prodPrice;

    while(fscanf(file, "%s %f %s", prodName, &prodPrice, prodCategory) == 3) {
        if(strcmp(prodCategory, category) == 0 && prodPrice >= minPrice && prodPrice <= maxPrice){
            printf("Prodotto: %s, Prezzo: %.2f\n", prodName, prodPrice);
        }
    }

    fclose(file);

    return 0;
}