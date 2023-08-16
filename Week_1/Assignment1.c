// DFA to accept set of all strings ending with two symbols of same type
#include <stdio.h>
#include <stdlib.h>
#define max 100

int main() {
    FILE *inputfile, *outputfile;
    char str[max], f = 'a';
    int i;

    inputfile = fopen("Input.txt", "r");
    if (inputfile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    outputfile = fopen("Output.txt", "w");
    if (outputfile == NULL) {
        perror("Error opening destination file");
        fclose(inputfile);
        return 1;
    }

    fscanf(inputfile, "%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case 'a':
                if (str[i] == '0')
                    f = 'b';
                else if (str[i] == '1')
                    f = 'd';
                break;

            case 'b':
                if (str[i] == '0')
                    f = 'c';
                else if (str[i] == '1')
                    f = 'a';
                break;

            case 'c':
                if (str[i] == '0')
                    f = 'a';
                else if (str[i] == '1')
                    f = 'a';
                break;

            case 'd':
                if (str[i] == '0')
                    f = 'a';
                else if (str[i] == '1')
                    f = 'c';
                break;
        }
    }

    if (f == 'c')
        fprintf(outputfile, "String is accepted\n");
    else
        fprintf(outputfile, "String is not accepted\n");

    fclose(inputfile);
    fclose(outputfile);

    printf("Result saved in Output.txt.\n");

    return 0;
}