// C program to demonstrate
// struct keyword
#include <stdio.h>
#include <string.h>

struct Books {
	char title[50];
	char author[50];
};

// Driver code
int main () {
	// Declare Book1 of type Book
	struct Books book1;

	// book 1 specification
	strcpy(book1.title, "C++ Programming");
	strcpy(book1.author, "Bjarne Stroustsup");

	// Print book details
	printf("Book One Title: %s\n", book1.title);
	printf("Book One Author: %s\n", book1.author);
	return 0;
}
