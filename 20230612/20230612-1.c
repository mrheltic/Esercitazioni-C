//
// Created by mrheltic on 13/07/24.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char surname[50];
    int age;
    float averageGrade;
} Student;

void addStudent(){
    FILE *file = fopen("archivio_studenti.dat", "ab");
    if (file == NULL){
        printf("Impossibile aprire il file archivio_studenti.dat\n");
        return;
    }

    Student student;

    printf("Inserisci il nome: ");
    scanf("%s", student.name);
    printf("Inserisci il cognome: ");
    scanf("%s", student.surname);
    printf("Inserisci l'eta: ");
    scanf("%d", &student.age);
    printf("Inserisci la media: ");
    scanf("%f", &student.averageGrade);

    fwrite(&student, sizeof(Student), 1, file);

    fclose(file);
}

void displayStudents(){
    FILE *file = fopen("archivio_studenti.dat", "rb");

    if (file == NULL){
        printf("Impossibile aprire il file archivio_studenti.dat\n");
        return;
    }

    Student student;

    while(fread(&student, sizeof(Student), 1, file)){
        printf("Nome: %s, Cognome: %s, Eta': %d, Voto medio: %.2f\n", student.name, student.surname, student.age, student.averageGrade);
    }

    fclose(file);
}

void calculateAverageGrade() {
    FILE *file = fopen("archivio_studenti.dat", "rb");

    if (file == NULL){
        printf("Impossibile aprire il file archivio_studenti.dat\n");
        return;
    }

    Student student;

    int count = 0;
    float total = 0;

    while(fread(&student, sizeof(Student), 1, file)){
        total += student.averageGrade;
        count++;
    }

    fclose(file);

    printf("Voto medio di tutti gli studenti: %.2f\n", total / count);

}

void findHighestGrade() {
    FILE *file = fopen("archivio_studenti.dat", "rb");

    if (file == NULL){
        printf("Impossibile aprire il file archivio_studenti.dat\n");
        return;
    }

    Student student, highestGradeStudent;

    float highestGrade;

    while(fread(&student, sizeof(Student), 1, file)){
        if (student.averageGrade > highestGrade) {
            highestGrade = student.averageGrade;
            highestGradeStudent = student;
        }
    }

    fclose(file);

    printf("Student with the highest grade:\nName: %s\nSurname: %s\nAge: %d\nAverage Grade: %.2f\n", highestGradeStudent.name, highestGradeStudent.surname, highestGradeStudent.age, highestGradeStudent.averageGrade);

}

int main(){
    int choice;

    do {
    printf("1. Add student\n2. Display students\n3. Calculate average grade\n4. Find student with highest grade\n5. Exit\n Enter your choice: ");
    scanf("%d", &choice);


    switch(choice) {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            calculateAverageGrade();
            break;

        case 4:
            findHighestGrade();
            break;

        case 5:
            break;

        default:
            printf("Invalid choice!\n");
    }
    } while (choice != 5);

    return 0;
}