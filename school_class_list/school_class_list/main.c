#include <stdio.h>
#include "person.h"


int main(void) {
	
	Person* person = person_new();
	strcpy(person->first_name, "John");
	strcpy(person->last_name, "Doe");
	person->year_of_birth = 1995;

	(*person->print)(person);

	return 0;
}