#include <stdio.h>

int main() {
	int age = 21;
	int *pAge = NULL; // A pointer is always of 8 bytes
	pAge = &age;
	
	printf("value of age : %d\n", *&age); // *& -> For Fun & curiosity
	printf("address of age : %p\n", &age);
	
	printf("value of pAge : %p\n", pAge);
	printf("address of pAge : %p\n", &pAge);
	printf("value stored at pAge : %d\n", *pAge);

	return 0;
}
