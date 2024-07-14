//
// Created by mrheltic on 05/07/24.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int find_max(struct Node* head) {
    if(head == NULL) {
        return 0;
    }
    else {
        int max_rest = find_max(head->next);
        return (head->data > max_rest) ? head->data : max_rest;
    }

}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;

}

int main(){
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printf("Il valore massimo nella lista e': %d\n", find_max(head));
}