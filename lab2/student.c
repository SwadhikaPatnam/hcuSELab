#include "student.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

stdClass *sClass;

// ≥ 90 → 0, 8590 → A+, 7585 → A, 6575 → B+, 6065 → B, 55-60 → C, 5055 → D, < 50 → F 
// assign grade
char* getGrade(int marks) {
	int value = marks / 5;
	switch (value) {
		case 20: return "O";
		case 19: return "O";
		case 18: return "O";
		case 17: return "A+";
		case 16: return "A";
		case 15: return "A";
		case 14: return "B+";
		case 13: return "B+";
		case 12: return "B";
		case 11: return "C";
		case 10: return "D";
		default: return "F";
	}
}

// assign point
int getPoint(int marks) {
	int value = marks / 5;
	switch (value) {
		case 20: return 10;
		case 19: return 10;
		case 18: return 10;
		case 17: return 9;
		case 16: return 8;
		case 15: return 8;
		case 14: return 7;
		case 13: return 7;
		case 12: return 6;
		case 11: return 5;
		case 10: return 4;
		default: return 0;
	}
	return 0;
}

// process student results
void calculateResults() {
	student *std = stdList;
	sClass = calloc(1,sizeof(stdClass));
	sClass->highPer = INT_MIN;
	sClass->lowPer = INT_MAX;
	// printf("%d %f\n", sClass->noStds, sClass->avgPer);
	while (std) {
		for (int i = 0; i < noSubjs; i++) {
			std->subj[i].total = std->subj[i].minor + std->subj[i].major;
			// printf("Total %d\n", std->subj[i].total);
			// assign grade and point
			std->subj[i].grade = getGrade(std->subj[i].total);
			// printf("Grade %s\n", std->subj[i].grade);
			std->subj[i].point = getPoint(std->subj[i].total);
			// printf("Point %d\n", std->subj[i].point);
			// gpa sum(points) / 5
			std->gpa += std->subj[i].point;
			// printf("Gpa sum %.2f\n", std->gpa);
			std->totalMarks += std->subj[i].total;
		}
		// printf("Gpa %.2f\n", std->gpa);
		std->gpa /= 5.0;
		
		// percentage is % total marks in all subjs 
		std->percentage = std->totalMarks / 5.0;
		
		// overall grade based on percentage
		std->overallGrade = getGrade(std->percentage);
		
		// avg % sum(%) / noStds
		sClass->avgPer += std->percentage;
		
		if (std->percentage > sClass->highPer)
			sClass->highPer = std->percentage;
		if (std->percentage < sClass->lowPer)
			sClass->lowPer = std->percentage;
		
		// get total grade --- using getPoint function
		int grade = getPoint((int)std->percentage);
		if (grade == 0)
			grade = 7;
		else
			grade = 10-grade;
		sClass->grade[grade]++;
		sClass->noStds++;
		std = std->next;
	}
	
	sClass->avgPer /= sClass->noStds * 1.0;
}

