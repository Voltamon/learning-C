#include <stdio.h>

int main() {
	unsigned short int age;

	printf("Enter your age : ");
	scanf("%hu", &age);

	if (age >= 18) printf("You are an adult!\n");
	else printf("You are still a kid!");

	return 0;
}
