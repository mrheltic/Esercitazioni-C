//
// Created by mrheltic on 13/07/24.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int errorCount;
    int replacedBits;
    float averageFlightDuration;
    int* correctedSignal;

} SignalInfo;

SignalInfo cleanSignal(int* S, int L, int K){
    int flightCount = 0;
    int flightDuration = 0;
    int totalFlightDuration = 0;
    int errorCount = 0;
    int replacedBits = 0;

    int* correctedSignal = (int*)malloc(L * sizeof(int));
    for (int i = 0; i < L; i++){
        correctedSignal[i] = S[i];
    }

    for (int i = 0; i < L; i++){
        if (correctedSignal[i] == 1){
            flightDuration++;
        }
        else if(flightDuration > 0){
            if(flightDuration < K){
                errorCount++;
                replacedBits += flightDuration;
                for(int j = i - flightDuration; j < i; j++){
                    correctedSignal[j] = 0;
                }
            }
            else{
                flightCount++;
                totalFlightDuration += flightDuration;
            }
            flightDuration = 0;
        }
    }

    SignalInfo info;
    info.errorCount = errorCount;
    info.replacedBits = replacedBits;
    info.averageFlightDuration = (float)totalFlightDuration / flightCount;
    info.correctedSignal = correctedSignal;

    return info;
}

int main(){
    int S[] ={0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0};

    int L = sizeof(S) / sizeof(int);

    int K = 5;

    SignalInfo info = cleanSignal(S, L, K);

    printf("Number of errors detected: %d\n", info.errorCount);
    printf("Number of bits replaced: %d\n", info.replacedBits);
    printf("Average duratio of valid flight phases: %.2f\n", info.averageFlightDuration);
    printf("Corrected signal: ");
    for (int i = 0; i < L; i++){
        printf("%d ",info.correctedSignal[i]);
    }
    printf("\n");

    free(info.correctedSignal);

    return 0;
}