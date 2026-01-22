#include "trie.h"
#include "student.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

Trie* root = NULL;

// check roll no		trie
bool isValidRollNo(char *rollNo) {
	if (root == NULL)
		root = calloc(1,sizeof(Trie));
	if (insert(rollNo) == 1)
		return false;
	return true;
}

// check name
// name should be have only alphabets
bool isValidName(char *name) {
	int len = strlen(name);
	for (int i = 0; i < len; i++)
		if (!isalpha(name[i]))
			return false;
	return true;
}

// check minor marks
bool isValidMinorMarks(int marks) {
	if (marks >= 0 && marks <= 40)
		return true;
	return false;
}

// check major marks
bool isValidMajorMarks(int marks) {
	if (marks >= 0 && marks <= 60)
		return true;
	return false;
}

bool isValidStdInfo(student *std) {

	// valid roll no
	if (!isValidRollNo(std->rollNo)) {
		printf("Invalid student roll no in input file, student roll no should be unique and alphanumeric\n");
		return false;
	}
	
	// valid name
	if (!isValidName(std->name)) {
		printf("Invalid student name in input file, student name should only contain alphabets\n");
		return false;
	}
	
	// valid marks checking
	
	for (int i = 0; i < noSubjs; i++) {
		// valid minor marks
		if (!isValidMinorMarks(std->subj[i].minor)) {
			printf("Invalid student minor marks in input file, student minor marks should be in the range 0-40\n");
			return false;
		}
	
		// valid major marks
		if (!isValidMajorMarks(std->subj[i].major)) {
			printf("Invalid student major marks in input file, student major marks should be in the range 0-60\n");
			return false;
		}
	}
	return true;
}













