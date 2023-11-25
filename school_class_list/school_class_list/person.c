#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include <string.h>

static void person_print(Person* this) {
	printf("Vorname:	%s\nNachname:	%s\nGeburtsjahr:	%d\n", this->first_name, this->last_name, this->year_of_birth);
}
/**
* Creates new Person and always makes it valid
* @param void
* @return an new Person
*/
Person* person_new() {
	
	int length = sizeof(struct _Person);
	Person* person = calloc(sizeof(char), length);
	person->print = &person_print;
	return person;
}