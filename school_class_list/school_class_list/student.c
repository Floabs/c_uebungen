#include <stdio.h>
#include <stdlib.h>>
#include <string.h>
#include "person.h"
#include "student.h"

static void student_print(Student* this) {
	this->person->print(this);
	printf("\n%d", this->mart_nr);
}

Person* student_new() {

	int length = sizeof(struct _Student);
	Student* student = calloc(sizeof(char), length);
	student->person = person_new();
	student->person->print = &student_print;
	return student;
}
