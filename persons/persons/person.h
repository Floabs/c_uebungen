#pragma once
#define MAX_STRING_LENGTH 40



struct Person{
	char first_name[MAX_STRING_LENGTH];
	char last_name[MAX_STRING_LENGTH];
	int size_cm;
};

typedef struct Person Person;
Person new_Person(const char* first_name, const char* last_name, int size_cm);