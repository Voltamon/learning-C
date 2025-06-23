#include <stdio.h>
#include <string.h>

int main() {
	char names[3][6] = {"Peter", "Bucky", "Simon"};
	strcpy(names[0], "Price");

	int size = sizeof(names) / sizeof(names[0]);

	printf("%zu\n", sizeof(names));

	for (int i = 0; i < size; i++) {
		printf("%s\n", names[i]);
	}

	return 0;
}
