#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 50

void translateFile(const char *inputFilename) {
    FILE *wefile, *translate, *output;
    char wefileLine[MAX_LINE_LENGTH];
    char translateLine[MAX_LINE_LENGTH];
    char outputLine[MAX_LINE_LENGTH];
    char cmdWe[MAX_LINE_LENGTH], cmdTrans[MAX_LINE_LENGTH];
    int x=0, y=0;
    char name[MAX_LINE_LENGTH];
    int curLine=0;

    for(int i=0; i<sizeof(*inputFilename); i++){
        if(inputFilename[i]=="."){
            i=MAX_LINE_LENGTH;
        }
        else{
            name[i]=inputFilename[i];
        }
    }

    wefile=fopen(inputFilename,"r+");
    translate=fopen("wordlist.txt","r");
    output=fopen(name,"w");

    if(wefile==NULL){
        printf("Blad przy wczytywaniu pliku zrodlowego wegorz.");
    }

    if(translate==NULL){
        printf("Blad przy wczytywaniu pliku z tlumaczeniami.");
    }

    while(fgets(wefileLine, sizeof(wefileLine), wefile) != NULL){
        for(int i=0; i<sizeof(wefileLine); i++){
            if(wefileLine[i]==" "){
                while((fgets(translate, sizeof(translateLine), translate) != NULL)){
                    for(int j=0; j<sizeof(translateLine); j++){
                        if(translateLine[j]==" "){
                            if(cmdWe==cmdTrans){
                                if(i>curLine){
                                    fprintf(output,"\n");
                                }
                                fprintf(output, "cmdTrans");
                                j=MAX_LINE_LENGTH;
                                curLine=i;
                            }
                        }
                        else{
                            cmdTrans[y]=translateLine[j];
                            y++;
                        }
                    }
                }

                x=0;
            }
            else{
                cmdWe[x]=wefileLine[i];
                x++;
            }
        }
    }

    fclose(wefile);
    fclose(translate);
    fclose(output);
    delete(wefile);
    delete(translate);
    delete(output);
}

int main(char *argv[]){
    const char *inputFilename = argv[1];
    translateFile(inputFilename);
    return 0;
}