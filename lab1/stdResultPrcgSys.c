#include <stdio.h>
#include <stdlib.h>
#include "fileOps.h"
#include "student.h"

int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "Invalid number of arguments. Please enter input file (student records) and output file (processed student records) name.\n");
		exit(EXIT_FAILURE);
	}
	
	const char* inputFile = argv[1];
	const char* outputFile = argv[2];
	
	// printf("Input file %s\n", inputFile);
	int status = parseFile(inputFile);
	if (status == 1) {
		exit(EXIT_FAILURE);
	}
	calculateResults();
	writeFile(outputFile);
	printf("Done processing student information\n");
	return 0;
}
