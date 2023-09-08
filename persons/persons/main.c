

#include <stdio.h>
#include "person.h"
static const char* JOHN = "John";
struct Node {
	Person person;
	struct Node *p_node;
};
Person createPersons() {
	const char* first_name = JOHN;
	Person person1 = new_Person(first_name, "Doe", 187);
	return person1;
}
int main() {
    Person person = createPersons();
    printf("Hello %s\n", person.last_name);}