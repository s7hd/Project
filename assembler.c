#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *in = fopen("fibonacci.asm", "r");
    if (in == NULL) {
        printf("File not found: fibonacci.asm\n");
        return 1;
    }

    FILE *fp = fopen("project.bin", "wb");
    if (fp == NULL) {
        printf("Could not create output file: project.bin\n");
        fclose(in);
        return 1;
    }

    printf("Starting Assembler...\nReading file: fibonacci.asm\n");
    char line[100];
    while (fgets(line, sizeof(line), in)) {
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "RA=RA+RB") == 0) {
            fwrite("00000000", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00000000\n", line);
        }
        else if (strcmp(line, "RB=RA+RB") == 0) {
            fwrite("00010000", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00010000\n", line);
        }
        else if (strcmp(line, "RA=RA-RB") == 0) {
            fwrite("00000100", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00000100\n", line);
        }
        else if (strcmp(line, "RB=RA-RB") == 0) {
            fwrite("00010100", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00010100\n", line);
        }
        else if (strcmp(line, "RO=RA") == 0) {
            fwrite("00100000", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00100000\n", line);
        }

	// RA start
        else if (strcmp(line, "RA=0") == 0) {
            fwrite("00001000", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00001000\n", line);
        } 
	 else if (strcmp(line, "RA=1") == 0) {
            fwrite("00001001", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00001001\n", line);
        }
	 else if (strcmp(line, "RA=2") == 0) {
            fwrite("00001010", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00001010\n", line);
        }
	else if (strcmp(line, "RA=3") == 0) {
            fwrite("00001011", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00001011\n", line);
        }
	else if (strcmp(line, "RA=4") == 0) {
            fwrite("00001100", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00001100\n", line);
        }
	else if (strcmp(line, "RA=5") == 0) {
            fwrite("00001101", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00001101\n", line);
        }
	else if (strcmp(line, "RA=6") == 0) {
            fwrite("00001110", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00001110\n", line);
        }
	else if (strcmp(line, "RA=7") == 0) {
            fwrite("00001111", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00001111\n", line);
        }
	// RA ends
	
	//-------------
	
	//RB start
        else if (strcmp(line, "RB=0") == 0) {
            fwrite("00011000", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00011000\n", line);
        }
       	else if (strcmp(line, "RB=1") == 0) {
            fwrite("00011001", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00011001\n", line);
        }
	else if (strcmp(line, "RB=2") == 0) {
            fwrite("00011010", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00011010\n", line);
        }
	else if (strcmp(line, "RB=3") == 0) {
            fwrite("00011011", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00011011\n", line);
        }
	else if (strcmp(line, "RB=4") == 0) {
            fwrite("00011100", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00011100\n", line);
        }
	else if (strcmp(line, "RB=5") == 0) {
            fwrite("00011101", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00011101\n", line);
        }
	else if (strcmp(line, "RB=6") == 0) {
            fwrite("00011110", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00011110\n", line);
        }
	else if (strcmp(line, "RB=7") == 0) {
            fwrite("00011111", 1, 8, fp);
            printf("Line: %s -> Machine Code: 00011111\n", line);
        }

	// RB ends

	//----------
	
	// JC starts
        else if (strcmp(line, "JC=0") == 0) {
            fwrite("01110000", 1, 8, fp);
            printf("Line: %s -> Machine Code: 01110000\n", line);
        }
	else if (strcmp(line, "JC=1") == 0) {
            fwrite("01110001", 1, 8, fp);
            printf("Line: %s -> Machine Code: 01110001\n", line);
        }
	else if (strcmp(line, "JC=2") == 0) {
            fwrite("01110010", 1, 8, fp);
            printf("Line: %s -> Machine Code: 01110010\n", line);
        }
	else if (strcmp(line, "JC=3") == 0) {
            fwrite("01110011", 1, 8, fp);
            printf("Line: %s -> Machine Code: 01110011\n", line);
        }
	else if (strcmp(line, "JC=4") == 0) {
            fwrite("01110100", 1, 8, fp);
            printf("Line: %s -> Machine Code: 01110100\n", line);
        }
	else if (strcmp(line, "JC=5") == 0) {
            fwrite("01110101", 1, 8, fp);
            printf("Line: %s -> Machine Code: 01110101\n", line);
        }
	else if (strcmp(line, "JC=6") == 0) {
            fwrite("01110110", 1, 8, fp);
            printf("Line: %s -> Machine Code: 01110110\n", line);
        }
	else if (strcmp(line, "JC=7") == 0) {
            fwrite("01110111", 1, 8, fp);
            printf("Line: %s -> Machine Code: 01110111\n", line);
        }
	// JC ends

	//------------
	
	// J starts
        else if (strcmp(line, "J=0") == 0) {
            fwrite("10110000", 1, 8, fp);
            printf("Line: %s -> Machine Code: 10110000\n", line);
        }
	 else if (strcmp(line, "J=1") == 0) {
            fwrite("10110001", 1, 8, fp);
            printf("Line: %s -> Machine Code: 10110001\n", line);
        }
	else if (strcmp(line, "J=2") == 0) {
            fwrite("10110010", 1, 8, fp);
            printf("Line: %s -> Machine Code: 10110010\n", line);
        }
	else if (strcmp(line, "J=3") == 0) {
            fwrite("10110011", 1, 8, fp);
            printf("Line: %s -> Machine Code: 10110011\n", line);
        }
	else if (strcmp(line, "J=4") == 0) {
            fwrite("10110100", 1, 8, fp);
            printf("Line: %s -> Machine Code: 10110100\n", line);
        }
	else if (strcmp(line, "J=5") == 0) {
            fwrite("10110101", 1, 8, fp);
            printf("Line: %s -> Machine Code: 10110101\n", line);
        }
	else if (strcmp(line, "J=6") == 0) {
            fwrite("10110110", 1, 8, fp);
            printf("Line: %s -> Machine Code: 10110110\n", line);
        }
	else if (strcmp(line, "J=7") == 0) {
            fwrite("10110111", 1, 8, fp);
            printf("Line: %s -> Machine Code: 10110111\n", line);
        }

	//J ends

        else {
            printf("Error: Unknown instruction '%s'\n", line);
            fclose(in);
            fclose(fp);
            return 1;
        }
    }

    printf("Successfully generated output file: project.bin\n");

    fclose(in);
    fclose(fp);
    return 0;
}
