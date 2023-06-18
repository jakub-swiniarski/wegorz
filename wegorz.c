#include <stdio.h>

int main(){
    FILE* file;
    file = fopen("wordlist.txt", "r");
    char line[100];
    
    if (file == NULL) {
        printf("Nie udalo sie otworzyc pliku zrodlowego wegorz.");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file); 
    return 0;
}