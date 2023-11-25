#pragma once
#include "person.h"

struct _Student {
	int mart_nr;
	Person *person;
};
typedef struct _Student Student;