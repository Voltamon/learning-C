#include <stdio.h>
#include <string.h>

int main() {
	char name[25]; // 25-bytes
	int age;
	
	printf("What is your name ? : ");
	// scanf("%s", name); // cuts the input at <white_space>
	fgets(name, 25, stdin);
	name[strlen(name) - 1] = '\0'; // as fgets() adds a \n at the last
	
	printf("What is your age ? : ");
	scanf("%d", &age);

	printf("Hello, %s\n", name);
	printf("You are %d years old", age);

	return 0;
}
