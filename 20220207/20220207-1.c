//
// Created by mrheltic on 14/07/24.
//
#include <stdio.h>
#include <string.h>

void findWordInSentence(char* sentence, char* word){
    char* result = strstr(sentence, word);

    if(result){
        printf("%d\n",(int)(result - sentence + 1));
    }
    else {
        printf("Stringa non trovata!");
    }
}



int main(){
    char sentence[] = "La volpe e l’uva.";
    char word1[] = "volpe";
    char word2[] = "uva";

    findWordInSentence(sentence, word1);

    findWordInSentence(sentence, word2);

    return 0;
}