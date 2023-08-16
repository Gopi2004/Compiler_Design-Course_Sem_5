#include <stdio.h>
#include <stdlib.h>
#define max 100
int main() {
    FILE *inputfile, *outputfile;
    char str[max], f = 'a';
    int i;

    inputfile = fopen("Input.txt", "r");
    if (inputfile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    outputfile = fopen("Output.txt", "w");
    if (outputfile == NULL) {
        perror("Error opening output file");
        fclose(inputfile);
        return 1;
    }

    fscanf(inputfile, "%s", str); // Read string from source file

    for (i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case 'a':
                if (str[i] == '0')
                    f = 'b';
                else if (str[i] == '1')
                    f = 'a';
                break;

            case 'b':
                if (str[i] == '0')
                    f = 'a';
                else if (str[i] == '1')
                    f = 'b';
                break;

           
        }
    }

    if (f == 'a')
        fprintf(outputfile, "String is accepted\n");
    else
        fprintf(outputfile, "String is not accepted\n");

    fclose(inputfile);
    fclose(outputfile);

    printf("String checked and result saved in destination_file.txt.\n");

    return 0;
}