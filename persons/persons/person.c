#include<stdio.h>
#include "person.h"

Person new_Person(const char* first_name, const char* last_name, int size_cm)
{
	Person person;
	strncpy(person.first_name, first_name, MAX_STRING_LENGTH);
	strncpy(person.last_name, last_name, MAX_STRING_LENGTH);
	person.size_cm = size_cm;

	return person;
}