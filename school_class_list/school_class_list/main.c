#include <stdio.h>
#include "person.h"
#include "student.h"

int main(void) {
	
	Student* student = student_new();
	strcpy(student->person->first_name, "John");
	strcpy(student->person->last_name, "Doe");
	student->person->year_of_birth = 1995;

	(*student->person->print)(student);

	/*Person* person = person_new();
	strcpy(person->first_name, "John");
	strcpy(person->last_name, "Doe");
	person->year_of_birth = 1995;

	(*person->print)(person);
	*/

	return 0;
}