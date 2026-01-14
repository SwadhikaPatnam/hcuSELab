#ifndef STUDENT_H
#define STUDENT_H

#include <stdbool.h>
#define noSubjs 5
#define noGrades 8

typedef struct {
	char* subname;
	int minor;
	int major;
	int total;
	char* grade;
	int point;
} subject;

typedef struct student {
	char *name;
	char *rollNo;
	subject subj[5];
	int totalMarks;
	float gpa;
	float percentage;
	char* overallGrade;
	struct student *next;
} student;

typedef struct {
	int noStds;
	float avgPer;
	float highPer;
	float lowPer;
	int grade[8];
} stdClass;

extern student* stdList;
extern stdClass *sClass;

bool isValidRollNo(char *rollNo);
bool isValidName(char *name);
bool isValidMinorMarks(int marks);
bool isValidMajorMarks(int marks);
char* getGrade(int marks);
int getPoint(int marks);
void calculateResults();

#endif
