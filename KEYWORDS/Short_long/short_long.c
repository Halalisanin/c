// C program to demonstrate
// short, long, signed
// and unsigned keyword
#include <stdio.h>

// Driver code
int main() {
	// short integer
	short int a = 12345;

	// signed integer
	signed int b = -34;

	// unsigned integer
	unsigned int c = 12;

	// L or l is used for
	// long int in C
	long int d = 99998L;

	printf("Integer value with a short int data: %hd\n", a);
	printf("Integer value with a signed int data : %d\n", b);
	printf("Integer value with an unsigned int data: %u\n", c);
	printf("Integer value with a long int date: %ld\n", d);
	
	return 0;
}
