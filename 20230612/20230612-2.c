//
// Created by mrheltic on 13/07/24.
//
#include <stdio.h>

void maxSumSubArray(float* arr, int len, int K){
    if (K > len) {
        printf("K  maggiore della lunghezza dell'array.\n");
        return;
    }

    float maxSum = 0;
    for (int i = 0; i < K; i++){
        maxSum += arr[i];
    }

    float windowSum = maxSum;
    int start = 0;

    for (int i = K; i < len; i++){
        windowSum += arr[i] - arr[i - K];
        if (windowSum > maxSum) {
            maxSum = windowSum;
            start = i - K + 1;
        }
    }

    printf("Il sottovettore di dimensione %d con la somma massima e': ", K);
    for ( int i = start; i < start + K;  i++){
        printf("%.2f ", arr[i]);
    }
    printf("\nLa somma vale %.2f", maxSum);
}

int main(){

    float arr[] = {1.5, 2.7, -3.2, 4.1, -2.0, 5.3, -1.8, 0.9};

    int len = sizeof(arr) / sizeof(float);
    int K = 3;

    maxSumSubArray(arr, len, K);

    return 0;
}