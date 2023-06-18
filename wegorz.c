#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 50

void translateFile(const char *inputFilename) {
    FILE *wefile, *translate;
    char wefileLine[MAX_LINE_LENGTH];
    char translateLine[MAX_LINE_LENGTH];

    wefile=fopen(inputFilename,"r+");
    translate=fopen("wordlist.txt","r");

    if(wefile==NULL){
        printf("Blad przy wczytywaniu pliku zrodlowego wegorz.");
        return 1;
    }

    if(translate==NULL){
        printf("Blad przy wczytywaniu pliku z tlumaczeniami.");
        return 1;
    }

    fclose(wefile);
    fclose(translate);
}

int main(char *argv[]){
    const char *inputFilename = argv[1];
    translateFile(inputFilename);
    return 0;
}