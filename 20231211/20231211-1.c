//
// Created by mrheltic on 06/07/24.
//

#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void addEmployee(struct Employee* employees, int* count){
    printf("Inserisci l'ID del dipendente: ");
    scanf("%d", &employees[*count].id);
    printf("Inserisci il nome del dipendente: ");
    scanf("%s", employees[*count].name);
    printf("Inserisci lo stipendio del dipendente: ");
    scanf("%f", &employees[*count].salary);
    (*count)++;
}

void displayEmployees(struct Employee* employees, int count) {
    for(int i = 0; i < count; i++) {
        printf("ID: %d\n", employees[i].id);
        printf("Nome: %s\n", employees[i].name);
        printf("Stipendio: %.2f\n\n", employees[i].salary);
    }
}

int searchEmployee(struct Employee* employees, int count, int empID) {
    for(int i = 0; i < count; i++) {
        if (employees[i].id == empID) {
            return i;
        }
    }
    return -1;
}


void updateEmployee(struct Employee* employees, int count, int empID) {
    int index = searchEmployee(employees, count, empID);
    if (index != -1) {
        printf("Inserisci il nuovo nome del dipendente: ");
        scanf("%s",employees[index].name);
        printf("Inserisci il nuovo stipendio del dipendente: ");
        scanf("%f",employees[index].salary);
    }
    else {
        printf("Dipendente non trovato \n");
    }
}

void deleteEmployee(struct Employee* employees, int* count, int empID) {
    int index = searchEmployee(employees, *count, empID);
    if (index != -1) {
        for (int i = index; i < (*count) ; i++) {
            employees[i] = employees[i+1];
        }
        (*count)--;
    }
    else {
        printf("Dipendente non trovato \n");
    }
}

int main(){
    struct Employee employees[50];
    int count = 0;
    int choice, empID;

    do {
        printf("\nGestione dipendenti\n");
        printf("1. Aggiungi dipendente\n");
        printf("2. Visualizzare dipendente\n");
        printf("3. Cercare dipendente\n");
        printf("4. Aggiornare dipendente\n");
        printf("5. Eliminare dipendente\n");
        printf("6. Esci\n");

        scanf("%d", &choice);

        switch (choice){
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees,count);
                break;
            case 3:
                printf(" Inserisci l'ID del dipendente da cercare: ");
                scanf("%d", &empID);
                searchEmployee(employees, count, empID);
                break;
            case 4:
                printf(" Inserisci l'ID del dipendente da aggiornare: ");
                scanf("%d", &empID);
                updateEmployee(employees, count, empID);
                break;
            case 5:
                printf(" Inserisci l'ID del dipendente da rimuovere: ");
                scanf("%d", &empID);
                deleteEmployee(employees, &count, empID);
                break;
            case 6:
                break;
            default:
                printf("Scelta non valida.\n");
        }
    } while (choice != 6);

    return 0;
}