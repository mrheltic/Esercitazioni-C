//
// Created by mrheltic on 04/07/24.
//
#include <stdio.h>

void compress_signal(float* V, int L){
    int N;

    do {
        printf("Inserisci un valore intero N che sia un divisore di %d: ", L);
        scanf("%d", &N);
    }
    while(L % N != 0);

    int new_lenght = L / N;

    float VC[new_lenght];

    for (int i = 0; i < new_lenght; i++){
        float sum = 0;
        for(int j = 0; j < N; j++){
            sum += V[i * N + j];
        }
        VC[i] = sum/N;
    }

    printf("Il vettore compresso e':\n");
    for(int i = 0; i < new_lenght; i++){
        printf("%.2f ", VC[i]);
    }
    printf("\n");
}

int main(){
    float V[] = {2.3 , 2.6 , 3.2 , 2.5 , 2.8 , 2.2};
    int L = sizeof(V)/sizeof(V[0]);

    compress_signal(V, L);
    return 0;
}