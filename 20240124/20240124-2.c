//
// Created by mrheltic on 05/07/2024.
//
#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per la lista collegata
struct Node {
    int data;
    struct Node* next;
};

// Funzione ricorsiva per trovare il valore massimo in una lista collegata
int find_max(struct Node* head) {
    // Caso base: se la lista è vuota, restituisci il valore minimo di un intero
    if (head == NULL) {
        return INT_MIN;
    }
    // Caso ricorsivo: restituisci il massimo tra il valore del nodo corrente e il massimo del resto della lista
    else {
        int max_rest = find_max(head->next);
        return (head->data > max_rest) ? head->data : max_rest;
    }
}

// Funzione per inserire un nuovo nodo all'inizio della lista
void push(struct Node** head_ref, int new_data) {
    // Alloca memoria per un nuovo nodo
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // Assegna i dati al nuovo nodo
    new_node->data = new_data;

    // Collega il nuovo nodo alla lista esistente
    new_node->next = (*head_ref);

    // Imposta il nuovo nodo come nuovo head della lista
    (*head_ref) = new_node;
}

int main() {
    // Crea una lista collegata vuota
    struct Node* head = NULL;

    // Inserisci alcuni valori nella lista
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    // Trova e stampa il valore massimo nella lista
    printf("Il valore massimo nella lista e': %d\n", find_max(head));

    return 0;
}
