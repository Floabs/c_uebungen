

#include <stdio.h>
#include <malloc.h>
#include "person.h"


static const char* JOHN = "John";
typedef struct Node Node;

struct Node {
	Person person;
	Node* next;
};

Node* new_node(const char *first_name)
{
	Node* p_node = calloc(1, sizeof(Node));
	p_node->next = NULL;
	strncpy(p_node->person.first_name, first_name, MAX_STRING_LENGTH);
	return p_node;
	//print_current_person(p_node->person, akutelle_anzahl_personen_in_liste, maximale_anzahl_personen);
}


void print_list(Node* starting_node)
{
	printf("%s\n", starting_node->person.first_name);
	if (starting_node->next != NULL)
	{
		print_list(starting_node->next);
	}	
}


void print_list2(Node* starting_node)
{
	for (Node* current = starting_node; current != NULL; current = current->next)
	{
		printf("%s\n", current->person.first_name);
	}
}

/*void print_current_person(const char* first_name, int akutelle_anzahl_personen_in_liste, int maximale_anzahl_personen)
{

	if (akutelle_anzahl_personen_in_liste <= maximale_anzahl_personen)
	{
		printf("%s\n", first_name);
	}
	else {
		printf("Ende der Liste.");
	}
}
*/

/* Person new_Person(const char* first_name, const char* last_name, int size_cm)
{
	Person person;
	strncpy(person.first_name, first_name, MAX_STRING_LENGTH);
	strncpy(person.last_name, last_name, MAX_STRING_LENGTH);
	person.size_cm = size_cm;
	 
	return new_person;
}
*/
int main() {
	



	Node* starting_address = NULL;
	Node* node1 = new_node("John");
	Node* node2 = new_node("Max");
	node1->next = node2;
	print_list2(node1);
	free(node2), node2 = NULL;
	free(node1), node1 = NULL;
	return 0;
}


/* 

john
p_node -> createPerson()
)

&new_node = NULL -> liste aus.

*/
