// An example to
// demonstrate working of
// enum
#include <stdio.h>

// enum declaration:
enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};

// Driver code
int main()
{
	// object of the enum (week), called day
	enum week day;
	day = Wed;
	printf("%d\n", day);
	return 0;
}
