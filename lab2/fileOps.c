#include "student.h"
#include "fileOps.h"
#include "validation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

student* stdList = NULL;

int parseFile(const char* fileName) {

	FILE *ip = fopen(fileName, "r");
	if (!ip) {
		fprintf(stderr, "Error opening input file %s\n", fileName);
		return 1;
	}
	
	char line[256];
	
	// token flag 0-rollNo, 1-name, 2-subj1name.....
	int tflag = 0;
	char* delimiters = " ,;\t\n";
	
	student *prev = NULL;
	student *std = NULL;
	
	// read each line
	
	while (fgets(line, sizeof(line), ip)) {
		// tokensize the line
		char* token = strtok(line, delimiters);
		
		// empty line
		if (!token) continue;
		
		while (token != NULL) {
			if (tflag == 0) { 	// roll no
			     
			    // new student record creation
			    std = calloc(1, sizeof(student)); 
			    std->rollNo = strdup(token);
			} 
			else if (tflag == 1) { 		// name
				std->name = strdup(token);
			} 
			else if ((tflag-2)%3 == 0) { 	// subjname
				 std->subj[(tflag-2)/3].subname = strdup(token);
			}
			else if ((tflag-2)%3 == 1) { 	// minor
				std->subj[(tflag-2)/3].minor = atoi(token);
			} 
			else if ((tflag-2)%3 == 2) { 	// major
				std->subj[(tflag-2)/3].major = atoi(token);
			}
			
			if (tflag == 16) {		// all 15 fields/tokens are read, now validate the student record validation 
				if (!isValidStdInfo(std))
					return 1;
			        // if first student initialise stdlist else attend the previous std record to list
				if (stdList == NULL)
				    stdList = std;
			   	else
			   	    	prev->next = std;
			   	prev = std;
			}
			
			tflag = (tflag + 1) % 17;
			token = strtok(NULL, delimiters);
		}
	}
	fclose(ip);
	return 0;
}

int writeFile(const char* fileName) {
	FILE *op = fopen(fileName, "w");
	fprintf(op, "StdRNO\tStdName\t");
	for (int i = 1; i <= noSubjs; i++) {
		fprintf(op, "Sub%d\tMinor\tMajor\tTotal\tGrade\tPoint\t", i);
	}
	fprintf(op, "TotalMarks\tGPA\tPercentage\tOverallGrade\n");
	
	student *std = stdList;
	
	while (std) {
		fprintf(op, "%s  %s\t", std->rollNo, std->name);
		for (int i = 0; i < noSubjs; i++) 
			fprintf(op, "%s\t%d\t%d\t%d\t%s\t%d\t", std->subj[i].subname, std->subj[i].minor, std->subj[i].major, std->subj[i].total, std->subj[i].grade, std->subj[i].point);
		fprintf(op, "%d\t%.2f\t%.2f\t%s\n", std->totalMarks, std->gpa, std->percentage, std->overallGrade);
		std = std->next;
	}
	
	fprintf(op, "\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	fprintf(op, "Class Average Percentage: %.2f\n", sClass->avgPer); 
	fprintf(op, "Class Highest Percentage: %.2f\n", sClass->highPer);
	fprintf(op, "Class Lowest Percentage: %.2f\n", sClass->lowPer);
	fprintf(op, "Number of students in each grade category\n");
	fprintf(op, "O: %d\nA+: %d\nA: %d\nB+: %d\nB: %d\nC: %d\nD: %d\nF: %d\n", sClass->grade[0], sClass->grade[1], sClass->grade[2], sClass->grade[3], sClass->grade[4], sClass->grade[5], sClass->grade[6], sClass->grade[7]);
	
	fclose(op);
	return 0;
}




