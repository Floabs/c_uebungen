#pragma once


struct _Person {
	int year_of_birth;
	char first_name[40];
	char last_name[40];
	void (*print)(struct _Person*);
};

typedef struct _Person Person;

Person* person_new();