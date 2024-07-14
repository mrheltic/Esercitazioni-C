//
// Created by mrheltic on 14/07/24.
//
#import <stdio.h>


void findElements(float* V1, int len1, float* V2, int len2, float** A, float** B){
    float sum = 0;
    for (int i = 0; i < len1; i++){
        sum += V1[i];
    }

    float average = sum / len1;

    *A, *B = NULL;

    for (int i = 0; i < len2; i++){
        if(V2[i] == average && *A == NULL){
            *A = &V2[i];
        }

        if(V2[i] == sum && *B == NULL){
            *B = &V2[i];
        }
    }
}

int main(){
    float V1[] = {1, 2, 3, 4};
    float V2[] = {5, 34, 10, 2.5};
    float *A, *B;

    findElements(V1, 4, V2, 4, &A, &B);

    if (A){
        printf("A: %f\n", *A);
    } else {
        printf("A: non trovato");
    }

    if (B){
        printf("B: %f\n", *B);
    } else {
        printf("B: non trovato");
    }

    return 0;
}