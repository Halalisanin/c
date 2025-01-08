// C program to demonstrate
// const keyword
#include <stdio.h>

// Driver code
int main()
{
	const int a = 11;
	a = a + 2;
	printf("%d\n", a); // This code is meant to produce an error
	return 0;
}
