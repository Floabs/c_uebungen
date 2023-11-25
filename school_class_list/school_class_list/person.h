#pragma once
/*
typedef struct {
	char first_name[40];
	char last_name[40];
	int year_of_birth;
} Person;
*/
//typedef void (*person_print)(struct _Person*);
struct _Person {
	char first_name[40];
	char last_name[40];
	int year_of_birth;
	void (*print)(struct _Person*);
};

typedef struct _Person Person;

Person* person_new();