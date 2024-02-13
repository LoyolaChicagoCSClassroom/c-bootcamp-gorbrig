#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[] = "example.txt";

    FILE *fw = fopen(filename, "w");
    if (fw == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        return 1;
    }

    fprintf(fw, "Hello, World!");
    fclose(fw);

    FILE *fr = fopen(filename, "r");
    if (fr == NULL) {
        fprintf(stderr, "Error opening file for reading\n");
        return 1;
    }

    char line[256]; 
    while (fgets(line, sizeof(line), fr) != NULL) {
        printf("%s", line);
    }

    fclose(fr);

    return 0;
}
