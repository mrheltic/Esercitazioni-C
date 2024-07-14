//
// Created by mrheltic on 12/07/24.
//
#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks[3];
};

void populate_students(struct Student *students, int size){
    for (int i = 0; i < size; i++){
        printf("Inserisci il nome dello studente %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Inserisci il numero di matricola dello studente %d: ", i + 1);
        scanf("%d", &students[i].rollNumber);
        printf("Inserisci i voti delle tre materie dello studente %d: ", i + 1);
        for ( int j = 0; j < 3; j++ ){
            scanf("%f", &students[i].marks[j]);
        }
    }
}

float calculate_average(struct Student *students){
    float sum = 0;
    for (int i = 0; i < 3; i++){
        sum += students->marks[i];
    }
    return sum/3;
}

void display_students(struct Student *students, int size){
    for (int i = 0; i < size; i++){
        float average = calculate_average(&students[i]);
        printf("Nome dello studente: %s\n", students[i].name);
        printf("Matricola dello studente: %d\n", students[i].rollNumber);
        printf("Voto medio: %.2f\n\n", average);
    }
}

int main(){
    const int SIZE = 3;

    struct Student students[SIZE];

    populate_students(students, SIZE);

    display_students(students, SIZE);

    return 0;
}