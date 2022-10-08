/*
 ============================================================================
 Name        : main.c
 Author      : Lucas Kelley
 Version     :
 Copyright   : Your copyright notice
 Description : Nucleotide Counter program
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	// Defining character arrays to store the names of input and output files
	char inFileName[BUFSIZ];
	char outFileName[BUFSIZ];

	// Prompts the user to input the name of the input file and saves it to inFileName
	puts("What is the name of the input file?");
	gets(inFileName);

	// Prompts the user to output the name of the input file and saves it to outFileName
	puts("What is the name of the output file?");
	gets(outFileName);

	// Opens outFile for writing and inFile for reading
	FILE *outFile = fopen(outFileName, "w");
	FILE *inFile = fopen(inFileName, "r");

	// Tests if inFile is open or doesn't exist then returns an error
	if (inFile == NULL) {
		perror("Error opening file");
		return (-1);
	}

	// Reads the first character of the file
	char character = fgetc(inFile);

	// While the character is not the End of File (EOF) character the loop executes
	while (character != EOF) {

		// Declares integers a, c, g, and t as zeros
		int a = 0, c = 0, g = 0, t = 0;

		// Executes the code in the loop while the character is not a new line (\n)
		do {

			// if the character is the End of File (EOF) character it breaks out of the loop
			if (character == EOF) {
				break;
			}

			// Switch statement to determine if character is one of the cases
			switch (character) {

			// Tests if the character is the letter A then adds 1 to the counter for a
			case 'A':
				a += 1;
				break;

			// Tests if the character is the letter C then adds 1 to the counter for c
			case 'C':
				c += 1;
				break;

			// Tests if the character is the letter G then adds 1 to the counter for g
			case 'G':
				g += 1;
				break;

			// Tests if the character is the letter T then adds 1 to the counter for t
			case 'T':
				t += 1;
				break;

			// Default case, if it is none of the cases above it exits the loop
			default:
				break;
			}

			// Reads the next character in the document
			character = fgetc(inFile);
		} while (character != '\n');
		// Prints the number of each letter separated by a space to the outFile
		fprintf(outFile, "%d %d %d %d\n", a, c, g, t);
	}

	// Closes both the inFile and the outFile
	fclose(inFile);
	fclose(outFile);

	// Prints "Complete" with the newline character (\n) to stdout
	printf("Complete\n");
}
