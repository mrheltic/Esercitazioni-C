//
// Created by mrheltic on 03/07/24.
//
#include <stdio.h>
#include <stdlib.h>

// Creazione della struttura
typedef struct point_3d{
    float x,y,z;
    int intensity;
    struct point_3d* next;
} point_3d;

// Creazione funzione per inserire ordinatamente
void insert_ordered(point_3d** head, point_3d* new_point){
    // Controllo se la lista vuota o intensita di new point minore della prima
    if (*head == NULL || (*head)->intensity > new_point->intensity){
    new_point->next = *head;
    *head = new_point;
    }
    else{
        point_3d* current = *head;
        while (current->next != NULL && current->next->intensity < new_point->intensity){
            current = current->next;
        }
        // Inserisci il nuovo punto
        new_point->next = current->next;
        current->next = new_point;
    }
}

int main(int argc, char* argv[]){

    // Verifica il passaggio del nome
    if (argc != 2){
        printf("File passato correttamente: %s\n", argv[1]);
        return 1;
    }

    // Apertura del file
    FILE* file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Errore nell'apertura del file: %s\n", argv[1]);
        return 1;
    }

    // Creazione della lista
    point_3d* head = NULL;

    while(!feof(file)) {
        point_3d* new_point = malloc(sizeof(point_3d));
        fscanf(file, "%f %f %f %d", &new_point->x, &new_point->y,  &new_point->z, &new_point->intensity);
        insert_ordered(&head, new_point);
    }

    fclose(file);

    point_3d* current = head;

    while (current != NULL) {
    printf("Punto: (%.2f, %.2f, %.2f), Intensita': %d\n", current->x, current->y, current->z, current->intensity);
    current = current->next;
    }

    while(head != NULL){
        point_3d* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;


}