#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdbool.h>

bool isValidStdInfo(student *std);
bool isValidRollNo(char *rollNo);
bool isValidName(char *name);
bool isValidMinorMarks(int marks);
bool isValidMajorMarks(int marks);

#endif
