//
// Created by mrheltic on 03/07/2024.
//
#include <stdio.h>
#include <stdlib.h>

// Utilizzando come parametro del programma 20240624/test.txt

// Definizione della struttura per un punto tridimensionale
typedef struct point_3d {
    float x, y, z; // Coordinate del punto
    int intensity; // Intensità di grigio del punto
    struct point_3d* next; // Puntatore al prossimo punto nella lista
} point_3d;

// Funzione per inserire un nuovo punto nella lista in modo ordinato
void insert_ordered(point_3d** head, point_3d* new_point) {
    // Se la lista è vuota o se l'intensità del nuovo punto è minore di quella del primo punto della lista
    if (*head == NULL || (*head)->intensity > new_point->intensity) {
        // Inserisci il nuovo punto all'inizio della lista
        new_point->next = *head;
        *head = new_point;
    } else {
        // Altrimenti, trova il punto corretto nella lista dove inserire il nuovo punto
        point_3d* current = *head;
        while (current->next != NULL && current->next->intensity < new_point->intensity) {
            current = current->next;
        }
        // Inserisci il nuovo punto dopo il punto corrente
        new_point->next = current->next;
        current->next = new_point;
    }
}

int main(int argc, char* argv[]) {
    // Verifica che il nome del file sia stato passato come argomento
    if (argc != 2) {
        printf("Uso: %s <nomefile>\n", argv[0]);
        return 1;
    }

    // Apri il file
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file %s\n", argv[1]);
        return 1;
    }

    // Crea una lista vuota di punti
    point_3d* head = NULL;

    // Leggi i punti dal file e inseriscili nella lista
    while (!feof(file)) {
        point_3d* new_point = malloc(sizeof(point_3d));
        fscanf(file, "%f %f %f %d", &new_point->x, &new_point->y, &new_point->z, &new_point->intensity);
        insert_ordered(&head, new_point);
    }

    // Chiudi il file
    fclose(file);

    // Stampa la lista di punti
    point_3d* current = head;

    while (current != NULL) {
        printf("Punto: (%.2f, %.2f, %.2f), Intensita': %d\n", current->x, current->y, current->z, current->intensity);
        current = current->next;
    }

    // Dealloca la memoria utilizzata per la lista
    while (head != NULL) {
        point_3d* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
