#include <stdio.h>
#include <string.h>

int main() {
	char name[50];

	do {
		printf("Enter your name : ");
		fgets(name, 50, stdin);
		name[strlen(name) - 1] = '\0';
	} while (strlen(name) == 0);

	printf("Hello %s\n", name);

	return 0;
}
