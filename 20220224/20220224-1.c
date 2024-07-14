//
// Created by mrheltic on 13/07/24.
//
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int wildcardMatch(char *str, char *strPattern){

    if(*strPattern == '\0' && *str == '\0'){
        return 1;
    }

    if(*strPattern == '*' && *(strPattern + 1)  != '\0' && *str == '\0'){
        return 0;
    }

    if (*strPattern == *str || *strPattern == '?'){
        return wildcardMatch(str +1, strPattern + 1);
    }

    if (*strPattern == '*'){
        return wildcardMatch(str + 1, strPattern) || wildcardMatch(str, strPattern + 1);
    }

    return 0;

}

int main(){
    FILE *file = fopen("20220224/list.txt", "r");
    char word[MAX_WORD_LENGTH];
    char searchWord[MAX_WORD_LENGTH];

    printf("Inserisci una parola da cercare: ");
    scanf("%s", searchWord);

    if (file == NULL){
        printf("Impossibile aprire il file\n");
        return 1;
    }

    while(fscanf(file, "%s\n", word) != EOF){
        if(wildcardMatch(word, searchWord)){
            printf("%s\n", word);
        }

        fclose(file);
    }


    return 0;
}