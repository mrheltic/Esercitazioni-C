//
// Created by mrheltic on 04/07/24.
//

#include <stdio.h>

int potenza_ricorsiva(int x, int e){
    if(e==0){
        return 1;
    }
    else{
        return x*potenza_ricorsiva(x,e-1);
    }
}

int potenza_iterativa(int x, int e){
    int risultato = 1;

    for(int i = 0; i < e; i++){
        risultato *= x;
    }

    return risultato;
}

int main(){
    int x = 2;
    int e = 10;

    int risultato_ricorsivo = potenza_ricorsiva(x, e);
    printf("Risultato ricorsivo: %d\n", risultato_ricorsivo);

    int risultato_iterativo = potenza_iterativa(x, e);
    printf("Risultato iterativo: %d\n", risultato_iterativo);

    return 0;
}